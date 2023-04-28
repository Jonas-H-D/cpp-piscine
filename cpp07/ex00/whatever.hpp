//
// Created by Jonas Hermon-Duc on 26/04/2023.
//

#ifndef CPPPROJECTS_WHATEVER_HPP
#define CPPPROJECTS_WHATEVER_HPP
#include <iostream>
#include <string>

/*Ces fonctions doivent pouvoir être appelées avec n’importe quel type d’argument à
seule condition que ces derniers aient le même type et supportent les opérateurs de comparaison.
 */
//Intervertit les valeurs de deux arguments donnés. Ne retourne rien.
template<typename T>
void swap(T &x, T &y){
    T tempX;
    T tempY;
    tempX = x;
    tempY = y;
    x = tempY;
    y = tempX;
};
// Compare les deux valeurs passées en argument et retourne la plus petite des
//deux. Si les deux sont équivalentes, alors retourne la seconde.
template<typename T>
T const &min(T const &x, T const &y){
    return(x<y ? x : y);
};
//Compare les deux valeurs passées en argument et retourne la plus grande
//des deux. Si les deux sont équivalentes, alors retourne la seconde.
template<typename T>
T const &max(T const &x, T const &y){
    return(x>y ? x : y);
};

#endif //CPPPROJECTS_WHATEVER_HPP
