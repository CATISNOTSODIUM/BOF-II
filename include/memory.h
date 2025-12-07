#ifndef BOF_MEMORY
#define BOF_MEMORY
#include "common.h"

static constexpr int SLOT_SIZE = 64;
using MemoryGrid = std::vector<std::array<int, SLOT_SIZE>>;

class Memory {
public:
    Memory();
    ~Memory();
    long long get_max();
    void expand_grid();
    // PC related methods
    int get_pc();
    void inc_pc();
    void dec_pc();
    int get_value_from_pc();
    // Increment / Decrement value
    void inc();
    void dec();
    void replace(int new_value);
private:
    int pc;
    MemoryGrid memory;
};

#endif