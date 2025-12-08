#ifndef BOF_COMMAND
#define BOF_COMMAND
#include "common.h"


class Memory;

enum Token {
    PLUS, MINUS, LEFT, RIGHT, INPUT, OUTPUT
};

struct Command {
    virtual ~Command() {}
    virtual void execute(Memory&) {
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
 * Represents + | - | > | < | . | , | <variable_name>
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

struct VariableStoreCommand : Command {
    VariableStoreCommand(std::string variable_name, std::shared_ptr<SequenceCommand> commands) 
        : commands(commands), variable_name(variable_name) {}
    void execute(Memory & m) override;
    std::shared_ptr<SequenceCommand> commands;
    std::string variable_name;
};

struct MacroStoreCommand : Command {
    MacroStoreCommand(std::string variable_name, std::shared_ptr<SequenceCommand> commands) 
        : commands(commands), variable_name(variable_name) {}
    void execute(Memory & m) override;
    std::shared_ptr<SequenceCommand> commands;
    std::string variable_name;
};

struct VariableReadCommand : Command {
    VariableReadCommand(std::string variable_name) 
        : variable_name(std::move(variable_name)) {}
    void execute(Memory & m) override;
    std::string variable_name;
};


SequenceCommand lex(std::string& s, size_t start, size_t end);

SequenceCommand lex_root(std::string& s);
#endif