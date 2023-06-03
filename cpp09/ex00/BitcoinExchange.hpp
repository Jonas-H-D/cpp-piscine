//
// Created by Jonas Hermon-Duc on 13/05/2023.
//

#ifndef CPPPROJECTS_BITCOINEXCHANGE_HPP
#define CPPPROJECTS_BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <map>

typedef struct date_s {
    int year;
    int month;
    int day;
} date_t;

typedef std::map<std::string, float> bitMap;

class BitcoinExchange {
public:
    BitcoinExchange(std::ifstream *argument, bitMap *bit_map);
    BitcoinExchange(const BitcoinExchange &other);
    ~BitcoinExchange();
    BitcoinExchange &operator=(const BitcoinExchange &other);

    int converter();
    int line_validation(const std::string line);
    int data_validation(const std::string &date_line);
    int error(std::string str);

private:
    std::string _date;
    double      _value;
    std::ifstream *_argument;
    bitMap        *_bit_map;

};


#endif //CPPPROJECTS_BITCOINEXCHANGE_HPP
