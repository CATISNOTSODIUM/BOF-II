#include <iostream>
#include "runner.h"

int main(int argc, const char** argv) {
    bool debug_mode = false;
    const char* file_name;

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-d") == 0) {
            debug_mode = true;
        } else {
            file_name = argv[i];
        }
    }

    if (argc <= 1) {
        InteractiveRunner runner{};
        runner.run();
    } else if (debug_mode == false) {
        FileRunner runner(file_name);
        runner.run();
    } else {
        DebugRunner runner(file_name);
        runner.run();
    }
    return 0;
}