/*
 * File: program.cpp
 * -----------------
 * This file is a stub implementation of the program.h interface
 * in which none of the methods do anything beyond returning a
 * value of the correct type.  Your job is to fill in the bodies
 * of each of these methods with an implementation that satisfies
 * the performance guarantees specified in the assignment.
 */

#include "program.hpp"



Program::Program() = default;

Program::~Program() = default;

void Program::clear() {
    // Replace this stub with your own code
    //todo
    source_line.clear();
    parse_line.clear();
}

void Program::addSourceLine(int lineNumber, const std::string &line) {
    // Replace this stub with your own code
    //todo
    if(source_line.count(lineNumber)) delete parse_line[lineNumber];
    source_line[lineNumber] = line;
    TokenScanner scanner = line;
    auto token = scanner.nextToken();//无行号的语句被basic部分直接处理。
    token = scanner.nextToken();
    if(token == "LET") parse_line[lineNumber] = new LET_Statement(line);
    else if(token == "PRINT") parse_line[lineNumber] = new PRINT_Statement(line);
    else if(token == "INPUT") parse_line[lineNumber] = new INPUT_Statement(line);
    else if(token == "GOTO") parse_line[lineNumber] = new GOTO_Statement(line);
    else if(token == "IF") parse_line[lineNumber] = new IF_Statement(line);
    else if(token == "RUN") parse_line[lineNumber] = new RUN_Statement(line);
    else if(token == "LIST") parse_line[lineNumber] = new LIST_Statement(line);
    else if(token == "CLEAR") parse_line[lineNumber] = new CLEAR_Statement(line);
    else if(token == "QUIT") parse_line[lineNumber] = new QUIT_Statement(line);
    else if(token == "HELP") parse_line[lineNumber] = new HELP_Statement(line);
    else if(token == "END") parse_line[lineNumber] = new END_Statement(line);
    else if(token == "REM") parse_line[lineNumber] = new REM_Statement(line);
    else error("illegal statement");
}

void Program::removeSourceLine(int lineNumber) {
    // Replace this stub with your own code
    //todo
    if(!source_line.count(lineNumber)) return;//不做操作
    source_line.erase(lineNumber);
    delete parse_line[lineNumber];
    parse_line.erase(lineNumber);
}

std::string Program::getSourceLine(int lineNumber) {
    // Replace this stub with your own code
    //todo
    if(!source_line.count(lineNumber)) return "";
    return source_line[lineNumber];
}

void Program::setParsedStatement(int lineNumber, Statement *stmt) {
    // Replace this stub with your own code
    //todo
    if(!parse_line.count(lineNumber)) { error("no such line"); return; }
    if(parse_line[lineNumber] != nullptr) delete parse_line[lineNumber];
    parse_line[lineNumber] = stmt;
}

Statement *Program::getParsedStatement(int lineNumber) {
   // Replace this stub with your own code
   //todo
   if(!parse_line.count(lineNumber) || parse_line[lineNumber] == nullptr) return nullptr;
   return parse_line[lineNumber];
}

int Program::getFirstLineNumber() {
    // Replace this stub with your own code
    //todo
    auto it = source_line.begin();
    if(it == source_line.end()) renturn -1;
    return it->first;
}

int Program::getNextLineNumber(int lineNumber) {
    // Replace this stub with your own code
    //todo
    auto it = source_line.find(lineNumber);
    if(it == source_line.end()) return -1;
    return (++it)->first;
}

//more func to add
//todo


