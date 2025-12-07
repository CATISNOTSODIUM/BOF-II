#include "runner.h"
#include "common.h"
#include "memory.h"
#include "command.h"

void InteractiveRunner::run() {
    std::cout << "Interactive session" << std::endl;
    std::string input;
    while (true) {
        std::getline(std::cin, input); // accept whitespace
        Memory mem{};
        try {
            lex_root(input).execute(mem);
            std::cout << mem.get_value_from_pc() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }
}