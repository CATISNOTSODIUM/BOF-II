
#include "command.h"

#define YELLOW "\033[33m"
#define RESET "\033[0m"

void BaseCommand::execute(Memory & mem) {
    for (auto c: tokens) {
        switch(c) {
            case RIGHT:
                mem.inc_pc(); break;
            case LEFT:
                mem.dec_pc(); break;
            case PLUS:
                mem.inc(); break;
            case MINUS:
                mem.dec(); break;
            case OUTPUT:
                std::cout << YELLOW << mem.get_value_from_pc() << RESET << std::endl; break;
            case INPUT:
                int val;
                std::cin >> val;
                mem.replace(val);
                break;
            default:
                break;
        }
    }
}

void LoopCommand::execute(Memory & mem) {
    while (mem.get_value_from_pc() != 0) {
        commands->execute(mem);
    }
}

void SequenceCommand::execute(Memory & mem) {
    for (auto c: commands) {
        c->execute(mem);
    }
}