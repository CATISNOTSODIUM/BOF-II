#include <iostream>
#include "runner.h"

int main(int argc, const char** argv) {
    if (argc <= 1) {
        InteractiveRunner runner{};
        runner.run();
    } else {
        FileRunner runner(argv[1]);
        runner.run();
    }
    return 0;
}