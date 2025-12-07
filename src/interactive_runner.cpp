#include "runner.h"
#include "common.h"
#include "memory.h"

#define YELLOW "\033[33m"
#define RESET "\033[0m"

void InteractiveRunner::run() {
    std::cout << "Interactive session" << std::endl;
    std::string input;
    while (true) {
        std::cin >> input;
        // ver 01: <, >, +, -, ., ,
        Memory mem{};
        for (auto c: input) {
            switch(c) {
                case ' ': 
                    break;
                case '>':
                    mem.inc_pc(); break;
                case '<':
                    mem.dec_pc(); break;
                case '+':
                    mem.inc(); break;
                case '-':
                    mem.dec(); break;
                case '.':
                    std::cout << YELLOW << mem.get_value_from_pc() << RESET << std::endl; break;
                case ',':
                    int val;
                    std::cin >> val;
                    mem.replace(val);
                    break;
                default:
                    break;
            }
        }
        std::cout << mem.get_value_from_pc() << std::endl;
    }
}