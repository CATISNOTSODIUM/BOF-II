#ifndef BOF_BINDING
#define BOF_BINDING
#include "common.h"
#include "command.h"

enum BindingType {
    VALUE, MACRO 
};

struct Binding {
    BindingType type;
    int value;
    std::shared_ptr<SequenceCommand> command;
    
    // Default constructor (important to make unordered_map work)
    Binding() : type(VALUE), value(0), command(nullptr) {}
    Binding(int v) : type(VALUE), value(v) {}
    Binding(std::shared_ptr<SequenceCommand> cmd) : type(MACRO), command(cmd) {}
};
#endif