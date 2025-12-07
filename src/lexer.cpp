#include "command.h"
#include "exception.h"

// `start` and `end` are treated as [start, end)

size_t scan_close_symbol(std::string& s, char input, char target, size_t start, size_t end) {
    int counter = 0;
    for (size_t i = start; i < end; i++) {
        if (s[i] != input && s[i] != target) continue;
        if (s[i] == input) counter++;
        else counter--;
        if (counter == 0) {
            return i;
        }
    }
    throw parse_expect_token_error(target);
}

SequenceCommand lex(std::string& s, size_t start, size_t end) {
    if (start > end || end > s.length()) {
        throw std::runtime_error("Invalid start/end");
    }
    size_t loc = start;
    std::vector<std::shared_ptr<Command>> commands;
    BaseCommand current{};
    while (loc < end) {
        char c = s[loc];
        if (c == '[') {
            size_t mark = scan_close_symbol(s, '[', ']', loc, end);
            SequenceCommand child_commands = lex(s, loc + 1, mark);
            if (current.tokens.size() > 0) {
                commands.emplace_back(std::make_shared<BaseCommand>(current));
            }
            commands.emplace_back(std::make_shared<LoopCommand>(LoopCommand(std::make_shared<SequenceCommand>(child_commands))));
            current = BaseCommand{};
            loc = mark + 1; continue;
        }
        switch(c) {
            case ' ': 
                break;
            case '>':
                current.tokens.push_back(RIGHT);
                break;
            case '<':
                current.tokens.push_back(LEFT);
                break;
            case '+':
                current.tokens.push_back(PLUS);
                break;
            case '-':
                current.tokens.push_back(MINUS);
                break;
            case '.':
                current.tokens.push_back(OUTPUT);
                break;
            case ',':
                current.tokens.push_back(INPUT);
                break;
            default:
                throw parse_unexpected_token_error(c);
                break;
        }
        loc++;
    }
    if (current.tokens.size() > 0) {
        commands.emplace_back(std::make_shared<BaseCommand>(current));
    }
    return SequenceCommand(commands);
}

SequenceCommand lex_root(std::string& s) {
    return lex(s, 0, s.length());
}