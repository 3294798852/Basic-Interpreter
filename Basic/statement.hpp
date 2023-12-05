/*
 * File: statement.h
 * ----------------- * This file defines the Statement abstract type.  In
 * the finished version, this file will also specify subclasses
 * for each of the statement types.  As you design your own
 * version of this class, you should pay careful attention to
 * the exp.h interface, which is an excellent m
 *
 */

#ifndef _statement_h
#define _statement_h

#include <string>
#include <sstream>
#include "evalstate.hpp"
#include "exp.hpp"
#include "Utils/tokenScanner.hpp"
#include "program.hpp"
#include "parser.hpp"
#include "Utils/error.hpp"
#include "Utils/strlib.hpp"

class Program;

/*
 * Class: Statement
 * ----------------
 * This class is used to represent a statement in a program.
 * The model for this class is Expression in the exp.h interface.
 * Like Expression, Statement is an abstract class with subclasses
 * for each of the statement and command types required for the
 * BASIC interpreter.
 */

class Statement {

public:

/*
 * Constructor: Statement
 * ----------------------
 * The base class constructor is empty.  Each subclass must provide
 * its own constructor.
 */

    Statement();

/*
 * Destructor: ~Statement
 * Usage: delete stmt;
 * -------------------
 * The destructor deallocates the storage for this expression.
 * It must be declared virtual to ensure that the correct subclass
 * destructor is called when deleting a statement.
 */

    virtual ~Statement();

/*
 * Method: execute
 * Usage: stmt->execute(state);
 * ----------------------------
 * This method executes a BASIC statement.  Each of the subclasses
 * defines its own execute method that implements the necessary
 * operations.  As was true for the expression evaluator, this
 * method takes an EvalState object for looking up variables or
 * controlling the operation of the interpreter.
 */

    virtual void execute(EvalState &state, Program &program) = 0;

};


/*
 * The remainder of this file must consists of subclass
 * definitions for the individual statement forms.  Each of
 * those subclasses must define a constructor that parses a
 * statement from a scanner and a method called execute,
 * which executes that statement.  If the private data for
 * a subclass includes data allocated on the heap (such as
 * an Expression object), the class implementation must also
 * specify its own destructor method to free that memory.
 */
class LET_Statement: public Statement{
public:
    LET_Statement(std::string);
    virtual void execute(EvalState &state, Program &program);
private:
    TokenScanner scanner;
};
class PRINT_Statement: public Statement{
public:
    PRINT_Statement(std::string);
    virtual void execute(EvalState &state, Program &program);
private:
    TokenScanner scanner;
};
class INPUT_Statement: public Statement{
public:
    INPUT_Statement(std::string);
    virtual void execute(EvalState &state, Program &program);
private:
    TokenScanner scanner;
};
class GOTO_Statement: public Statement{
public:
    GOTO_Statement(std::string);
    virtual void execute(EvalState &state, Program &program);
private:
    TokenScanner scanner;
};
class IF_Statement: public Statement{
public:
    IF_Statement(std::string);
    virtual void execute(EvalState &state, Program &program);
private:
    TokenScanner scanner;
};
class RUN_Statement: public Statement{
public:
    RUN_Statement(std::string);
    virtual void execute(EvalState &state, Program &program);
private:
    TokenScanner scanner;
};
class LIST_Statement: public Statement{
public:
    LIST_Statement(std::string);
    virtual void execute(EvalState &state, Program &program);
private:
    TokenScanner scanner;
};
class CLEAR_Statement: public Statement{
public:
    CLEAR_Statement(std::string);
    virtual void execute(EvalState &state, Program &program);
private:
    TokenScanner scanner;
};
class QUIT_Statement: public Statement{
public:
    QUIT_Statement(std::string);
    virtual void execute(EvalState &state, Program &program);
private:
    TokenScanner scanner;
};
class HELP_Statement: public Statement{
public:
    HELP_Statement(std::string);
    virtual void execute(EvalState &state, Program &program);
private:
    TokenScanner scanner;
};
class END_Statement: public Statement{
public:
    END_Statement(std::string);
    virtual void execute(EvalState &state, Program &program);
private:
    TokenScanner scanner;
};
class REM_Statement: public Statement{
public:
    REM_Statement(std::string);
    virtual void execute(EvalState &state, Program &program);
private:
    TokenScanner scanner;
};
#endif
