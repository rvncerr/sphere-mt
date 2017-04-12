#include "gtest/gtest.h"
#include <sstream>

#include <coroutine/engine.h>

int _calculator_add(int left, int right) {
    return left + right;
}

TEST(CoroutineTest, SimpleStart) {
    Coroutine::Engine engine;
    int result = engine.start(_calculator_add, 1, 2);

    ASSERT_EQ(3, result);
}

void printa(Coroutine::Engine* pe, std::ostream& out, const int& other) {
    out << "A1 ";
    pe->sched(other);

    out << "A2 ";
    pe->sched(other);

    out << "A3 ";
    pe->sched(other);
}

void printb(Coroutine::Engine* pe, std::ostream& out, const int& other) {
    out << "B1 ";
    pe->sched(other);

    out << "B2 ";
    pe->sched(other);

    out << "B3 ";
    pe->sched(other);
}

std::string _printer(Coroutine::Engine* pe) {
    int pa, pb;
    std::stringstream out;

    // Create routines, note it doens't get control yet
    pa = pe->run(printa, pe, &out, pb);
    pb = pe->run(printb, pe, &out, pa);

    // Pass control to first routine, it will ping pong
    // between printa/printb greedely then we will get
    // contol back
    pe->sched(pa);
    out << "END";

    // done
    return out.str();
}

TEST(CoroutineTest, Printer) {
    Coroutine::Engine engine;
    std::string res = engine.start(_printer, &engine);
    ASSERT_STREQ("A1 B1 A2 B2 A3 B3 END", res.c_str());
}
