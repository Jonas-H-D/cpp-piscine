//
// Created by Jonas Hermon-Duc on 23/05/2023.
//

#ifndef CPPPROJECTS_RPN_HPP
#define CPPPROJECTS_RPN_HPP
#include <iostream>
#include <string>
#include <stack>

class RPN {
private:
    double              _tmp1;
    double              _tmp2;
    std::string         _input;
    std::stack<double>  _stack;
public:
    RPN(std::string argument);
    RPN(const RPN &other);
    ~RPN();

    RPN &operator=(const RPN &other);
    int parsing();
    void calculate(int arg);
    void cal_init();

};


#endif //CPPPROJECTS_RPN_HPP
