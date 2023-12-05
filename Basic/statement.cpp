/*
 * File: statement.cpp
 * -------------------
 * This file implements the constructor and destructor for
 * the Statement class itself.  Your implementation must do
 * the same for the subclasses you define for each of the
 * BASIC statements.
 */

#include "statement.hpp"


/* Implementation of the Statement class */

int stringToInt(std::string str);

Statement::Statement() = default;

Statement::~Statement() = default;

//todo
LET_Statement::LET_Statement(std::string line) {
    scanner = TokenScanner(line);
}

void LET_Statement::execute(EvalState &state, Program &program) {

}

PRINT_Statement::PRINT_Statement(std::string line) {
    scanner = TokenScanner(line);
}

INPUT_Statement::INPUT_Statement(std::string line) {
    scanner = TokenScanner(line);
}

GOTO_Statement::GOTO_Statement(std::string line) {
    scanner = TokenScanner(line);
}

IF_Statement::IF_Statement(std::string line) {
    scanner = TokenScanner(line);
}

RUN_Statement::RUN_Statement(std::string line) {
    scanner = TokenScanner(line);
}

LIST_Statement::LIST_Statement(std::string line) {
    scanner = TokenScanner(line);
}

CLEAR_Statement::CLEAR_Statement(std::string line) {
    scanner = TokenScanner(line);
}

QUIT_Statement::QUIT_Statement(std::string line) {
    scanner = TokenScanner(line);
}

HELP_Statement::HELP_Statement(std::string line) {
    scanner = TokenScanner(line);
}

END_Statement::END_Statement(std::string line) {
    scanner = TokenScanner(line);
}

REM_Statement::REM_Statement(std::string line) {
    scanner = TokenScanner(line);
}
