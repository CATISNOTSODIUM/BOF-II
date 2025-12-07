#include "memory.h"
#include "command.h"

Memory::Memory() {
    memory = MemoryGrid(1, std::array<int, SLOT_SIZE>{0});
    pc = 0;
}

Memory::~Memory() {}

long long Memory::get_max() {
    return (long long) memory.size() * SLOT_SIZE;
}

int Memory::get_pc() {
    return pc;
}

void Memory::inc_pc() {
    pc++;
    if (pc >= get_max()) {
        expand_grid();
    }
}
void Memory::dec_pc() {
    pc--;
    pc = std::max(pc, 0);
}

void Memory::expand_grid() {
    memory.push_back(std::array<int, SLOT_SIZE>{0});
}

int Memory::get_value_from_pc() {
    int pc_slot = pc / SLOT_SIZE;
    int pc_offset = pc % SLOT_SIZE;
    return memory[pc_slot][pc_offset];
}

void Memory::inc() {
    int pc_slot = pc / SLOT_SIZE;
    int pc_offset = pc % SLOT_SIZE;
    memory[pc_slot][pc_offset]++;
}

void Memory::dec() {
    int pc_slot = pc / SLOT_SIZE;
    int pc_offset = pc % SLOT_SIZE;
    memory[pc_slot][pc_offset]--;
}

void Memory::replace(int new_value) {
    int pc_slot = pc / SLOT_SIZE;
    int pc_offset = pc % SLOT_SIZE;
    memory[pc_slot][pc_offset] = new_value;
}

bool Memory::find_variable(std::string symbol) {
    return symbol_table.find(symbol) != symbol_table.end();
}

int Memory::get_variable(std::string symbol) {
    return symbol_table[symbol];
}

void Memory::store_variable(std::string symbol, int value) {
    symbol_table[symbol] = value;
}

/*
bool Memory::find_macro(std::string symbol) {
    return macro_table.find(symbol) != macro_table.end();
}

void Memory::run_macro(std::string symbol) {
    if (find_macro(symbol)) {
        macro_table[symbol]->execute(*this);
    }
}

void Memory::store_macro(std::string symbol, std::shared_ptr<SequenceCommand> value) {
    macro_table[symbol] = value;
}
*/