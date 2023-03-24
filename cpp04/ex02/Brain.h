//
// Created by Jonas Hermon-Duc on 22/03/2023.
//

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <string.h>

class Brain {
public:
    std::string ideas[100];

    Brain();
    Brain(Brain const &other);
    Brain& operator=(Brain const &rhs);
    ~Brain();
};

#endif
