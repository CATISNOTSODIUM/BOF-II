
#include "command.h"
#include "exception.h"
#include "memory.h"

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

void VariableReadCommand::execute(Memory & mem) {
    if (!mem.find_variable(variable_name)) {
        throw runtime_undefined_variable(variable_name);
    }
    auto cmd = mem.get_variable(variable_name);
    if (cmd.type == MACRO) {
        cmd.command->execute(mem);
    } else {
        mem.replace(cmd.value);
    }
}

// Call by value semantics
void VariableStoreCommand::execute(Memory & mem) {
    // execute command first
    commands->execute(mem);
    // store the value in pc as a variable
    mem.store_variable(variable_name, mem.get_value_from_pc());
}

// Call by name semantics
void MacroStoreCommand::execute(Memory & mem) {
    // store the value in pc as a variable
    mem.store_macro(variable_name, commands);
}