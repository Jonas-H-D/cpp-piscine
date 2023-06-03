//
// Created by Jonas Hermon-Duc on 13/05/2023.
//

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream *argument, bitMap *bit_map){
    _argument = argument;
    _bit_map = bit_map;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    this->_argument = other._argument;
    this->_bit_map = other._bit_map;
    return (*this);
}

int BitcoinExchange::error(std::string str) {
    std::cout << str << std::endl;
    return (0);
}

int BitcoinExchange::data_validation(const std::string &date_line) {
    struct tm   date;
    time_t      t;
    date_t      d;

    d.year = std::atoi(date_line.substr(0, 4).c_str()) - 1900;
    d.month = std::atoi(date_line.substr(5,2).c_str()) - 1;
    d.day = std::atoi(date_line.substr(8, 2).c_str());

    std::memset(&date, 0, sizeof(date));
    date.tm_year = d.year;
    date.tm_mon = d.month;
    date.tm_mday = d.day;
    t = std::mktime(&date);

    if (t == -1 || date.tm_year != d.year || date.tm_mon != d.month || date.tm_mday != d.day)
        return 0;
    return 1;
}

int BitcoinExchange::line_validation(const std::string line){
    _date = line.substr(0, 10);
    if (line.length() < 14 || line[4] != '-' || line[7] != '-' || !data_validation(_date))
        return (error("Error: invalid format: " + line));
    _value = std::atof(line.substr(13).c_str());
    if (!_value || _value < 0)
        return (error("Error: invalid value, must be positive int"));
    if(_value > 1000)
        return (error("Error: invalid value, can't be higher than 1000"));
    return 1;
}

int BitcoinExchange::converter() {
    std::string line;
    bitMap::iterator it;

    std::getline(*_argument, line, '\n');
    while(std::getline(*_argument, line, '\n')){
        if (!line_validation(line))
            continue;
        it = _bit_map->upper_bound(line.substr(0, 10));
        --it;
        std::cout << _date << " => " << _value << " = " << it->second * _value << std::endl;

    }
    return 0;
}