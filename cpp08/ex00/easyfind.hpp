//
// Created by Jonas Hermon-Duc on 05/05/2023.
//

#ifndef CPPPROJECTS_EASYFIND_HPP
#define CPPPROJECTS_EASYFIND_HPP
// STL : Standard template library containing a collection of templates
//representing containers, iterator, algorithms and fct objects.
//A container is an object that stores a collection of objects of a
// specific type.
// For example, if we need to store a list of names, we can use a vector.
/* 3 types of containers: Sequential / Associative / Unordered Associative
Sequential containers allow us to
store elements that can be accessed in sequential order.
Types of SEQUENTIAL Containers:
Vector
Deque
List
*/
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <exception>

class ElementNotFoundException : public std::exception {
public:
    const char* what() const throw() {
        return "Element not found in container";
    }
};

template<typename T>
typename T::iterator containerFind(T& container, int y){
    typename T::iterator it = std::find(container.begin(), container.end(), y);
    if (it == container.end())
        throw ElementNotFoundException();
    return it;
}

template<typename T>
void easyfind(T& container, int y){
    try {
        typename T::iterator it = containerFind(container, y);
        std::cout << "First occurrence of the Value is in Index position " << std::distance(container.begin(), it) << std::endl;
    }
    catch(const std::exception& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
}

#endif //CPPPROJECTS_EASYFIND_HPP
