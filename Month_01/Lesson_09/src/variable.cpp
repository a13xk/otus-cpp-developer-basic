#include "variable.h"
Variable::Variable(std::string val) :
    ASTNode(val),
    val_(val){}

std::string Variable::value() const {
    return val_;
}