//
// Created by Jonas Hermon-Duc on 26/04/2023.
//

#ifndef CPPPROJECTS_ITER_HPP
#define CPPPROJECTS_ITER_HPP

#include "iostream"

template<typename T, typename V>
void   iter(T arr[], size_t u, V z){
    for (int i = 0; i < u; i++){
        z(arr[i]);
    }
};

template<typename T>
void function(T x){
    std::cout << "tab element: " << x << std::endl;
};

#endif //CPPPROJECTS_ITER_HPP
