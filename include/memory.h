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

    bool find_variable(std::string symbol);
    int get_variable(std::string symbol);
    void store_variable(std::string symbol, int value);

    // bool find_macro(std::string symbol);
    // void run_macro(std::string symbol);
    // void store_macro(std::string symbol, std::shared_ptr<SequenceCommand> value);
private:
    int pc;
    MemoryGrid memory;
    // basic environment
    std::unordered_map<std::string, int> symbol_table;
    // std::unordered_map<std::string, std::shared_ptr<SequenceCommand>> macro_table;
};

#endif