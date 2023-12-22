#include "stdafx.h"
#include "funcs.h"
#include "globals.h"
#include "rooms.h"
#include <vector>
#include <chrono>
#include <thread>

namespace Zork {
    class OutputBuf : public std::basic_stringbuf<char, std::char_traits<char>> {
    public:
        ~OutputBuf() override = default;

    protected:
        int sync() override {
            const auto s = this->str();
            if (!e_useQueue) {
                std::cout << s;
                if (script_channel) {
                    (*script_channel) << s;
                    script_channel->flush();
                }
                this->str("");
                return 0;
            } else {

                const auto res = e_outputQueue.try_emplace(s);
                if (script_channel) {
                    (*script_channel) << s;
                    script_channel->flush();
                }
                this->str("");
                return 0;
            }
        }
    };
} // namespace Zork
// Output stream, supporting scripting.
class TtyBuff : public std::basic_stringbuf<char, std::char_traits<char>> {
protected:
    int sync() override {
        auto s = this->str();
        std::cout << s;
        if (script_channel) {
            (*script_channel) << s;
            script_channel->flush();
        }
        this->str("");
        return 0;
    }
};

/* TtyBuff tty_buf; */
Zork::OutputBuf tty_buf;
std::ostream tty(&tty_buf);

std::string& substruc(const std::string& src, size_t start, size_t end, std::string& dest) {
    _ASSERT(dest.size() >= end);
    std::copy(src.begin() + start, src.begin() + end, dest.begin() + start);
    return dest;
}

char* substruc(const char* src, size_t start, size_t end, char* dest) {
    _ASSERT(start == 0); // Verify functionality if not true.
    while (start != end) {
        dest[start] = src[start];
        ++start;
    }
    return dest;
}

int readst_from_queue(std::string& buffer, std::string_view prompt) {
    bool res = false;
    do {
        res = e_inputQueue.try_dequeue(buffer);
    } while (!res);
    if (script_channel) {
        (*script_channel) << buffer << std::endl;
    }
    return static_cast<int>(buffer.size());
}

int readst(std::string& buffer, std::string_view prompt) {
    if (e_useQueue) {
        return readst_from_queue(buffer, prompt);
    }
    // output ">"
    tty << prompt;
    tty.flush();
    std::getline(std::cin, buffer);
    if (script_channel) {
        (*script_channel) << buffer << std::endl;
    }
    return (int)buffer.size();
}


SIterator uppercase(SIterator src) {
    std::transform(src.begin(), src.end(), src.begin(), [](char c) { return toupper(c); });
    return src;
}
