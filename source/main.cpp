#include "zork.h"
#include "globals.h"
#include <thread>
#include <iostream>
int main() {
    auto threadFunc = []() {
        const auto res = Zork::startZork(true);
    };
    std::atomic_bool exit{ false };
    auto ioFunc = [&exit]() {
        while (!exit.load()) {
            bool res{ false };
            do {
                std::string op{};
                res = e_outputQueue.try_dequeue(op);
                if (!res) continue;
                std::cout << op;
            } while (res);
        }
    };
    std::thread zorkThread{ std::move(threadFunc) };
    std::thread ioThread{ std::move(ioFunc) };
    zorkThread.detach();
    ioThread.detach();
    while (!exit.load()) {
        std::string userIn{};
        std::getline(std::cin, userIn);
        e_inputQueue.enqueue(userIn);
        if (userIn == "quit") {
            e_inputQueue.enqueue("y");
            exit.store(true);
        }
    }

    return 0;
}
