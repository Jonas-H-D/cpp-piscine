//
// Created by Jonas Hermon-Duc on 23/05/2023.
//

#include "RPN.hpp"

int error_print(std::string stg){
    std::cout << "Error: " << stg << std::endl;
    return 0;
}

RPN::RPN(std::string argument){
    _input = argument;
    cal_init();
}

RPN::RPN(const RPN &other){
    *this = other;
}

RPN::~RPN(){}

RPN &RPN::operator=(const RPN &other) {
    this->_input = other._input;
    this->cal_init();
    return *this;
}

void    RPN::cal_init(){
    int i = -1;
    if (!parsing())
        return ;
    while(this->_input[++i]) {
        if (isdigit(this->_input[i]))
            this->_stack.push(this->_input[i] - 48);
        else if (!isspace(this->_input[i]))
            calculate(this->_input[i]);
    }
    std::cout << this->_stack.top() << std::endl;
}

void   RPN::calculate(int value){
    this->_tmp1 = this->_stack.top();
    this->_stack.pop();
    this->_tmp2 = this->_stack.top();
    this->_stack.pop();
    if (value == '+')
        this->_stack.push(this->_tmp2 + this->_tmp1);
    if (value == '-')
        this->_stack.push(this->_tmp2 - this->_tmp1);
    if (value == '*')
        this->_stack.push(this->_tmp2 * this->_tmp1);
    if (value == '/')
        this->_stack.push(this->_tmp2 / this->_tmp1);
}

int RPN::parsing() {
    char    c;
    int     i;

    i = -1;
    while(this->_input[++i]){
        c = this->_input[i];
        if (c != ' '){
            if (c != '+' && c != '-' && c != '*' && c != '/')
                if (!isdigit(c))
                    return error_print("Bad input");
        if (this->_input[i + 1] == '\0' && isdigit(c))
            return error_print("RPN should finish with operand");
        }
    }
    return 1;
}

