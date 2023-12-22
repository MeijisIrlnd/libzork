#include <catch2/catch_test_macros.hpp>
#include "zork_TestHelpers.h"
#include "../source/globals.h"
TEST_CASE("Liminal Space") {
    REQUIRE(1 == 1);
}
TEST_CASE("Test exit flag") {
    e_inputQueue.enqueue("quit");
    e_inputQueue.enqueue("y");
    REQUIRE(Zork::Testing::run() == 0);
}
// Test a known path..
TEST_CASE("Test Enter Kitchen") {
    e_inputQueue.enqueue("north");
    e_inputQueue.enqueue("east");
    e_inputQueue.enqueue("open window");
    e_inputQueue.enqueue("enter");
    e_inputQueue.enqueue("quit; y");
    REQUIRE(Zork::Testing::run() == 0);
}
