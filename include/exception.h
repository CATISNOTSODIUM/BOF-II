#ifndef BOF_EXCEPTION
#define BOF_EXCEPTION
#include "common.h"

struct parse_unexpected_token_error : public std::runtime_error {
    parse_unexpected_token_error(char c)
        : std::runtime_error("Unexpected token: '" + std::string(1, c) + "'") {
    }
};

struct parse_expect_token_error : public std::runtime_error {
    parse_expect_token_error(char c)
        : std::runtime_error("Expect token: '" + std::string(1, c) + "'") {
    }
};
#endif