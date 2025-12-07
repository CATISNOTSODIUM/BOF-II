#ifndef BOF_COMMAND
#define BOF_COMMAND
#include "common.h"
#include "memory.h"

enum Token {
    PLUS, MINUS, LEFT, RIGHT, INPUT, OUTPUT
};

struct Command {
    virtual ~Command() {}
    virtual void execute(Memory & m) {
        std::cout << "execute virtual" << std::endl;
    }
};


struct SequenceCommand : Command {
    SequenceCommand(std::vector<std::shared_ptr<Command>> commands) 
        : commands(std::move(commands)) {}
    
    void execute(Memory & m) override;
    
    std::vector<std::shared_ptr<Command>> commands;
};

/**
 * Represents + | - | > | < | . | , 
 */
struct BaseCommand : Command {
    void execute(Memory & m);
    std::vector<Token> tokens;
};

struct LoopCommand : Command {
    LoopCommand(std::shared_ptr<SequenceCommand> commands) 
        : commands(std::move(commands)) {}
    void execute(Memory & m) override;
    std::shared_ptr<SequenceCommand> commands;
};

SequenceCommand lex(std::string& s, size_t start, size_t end);

SequenceCommand lex_root(std::string& s);
#endif