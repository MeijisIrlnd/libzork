#include "zork_TestHelpers.h"
#include "../source/globals.h"
#include <iostream>
#include <thread>
namespace Zork::Testing {
    int run() {
        std::atomic_bool exit{ false };
        auto zorkLambda = [&exit]() {
            const auto res = startZork(true);
            exit.store(true);
        };
        auto ioLambda = [&exit]() {
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
        std::thread zorkThread{ zorkLambda };
        std::thread ioThread{ ioLambda };
        zorkThread.detach();
        ioThread.detach();
        while (!exit.load()) {
        }
        return 0;
    }

} // namespace Zork::Testing