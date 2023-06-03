#include "BitcoinExchange.hpp"

int error_out(std::string str){
    std::cout << str << std::endl;
    return (1);
}
int main(int argc, char **argv) {
    std::string     line;
    std::ifstream   argument;
    std::ifstream   bit_data;
    bitMap          bit_map;

    std::cout.precision(7);
    if (argc != 2) {
        return (error_out("Error: Program needs a valid data file as argument"));
    }
    argument.open(argv[1], std::ifstream::in);
    bit_data.open("./data.csv", std::ifstream::in);
    if (!argument)
        return(error_out("Error: file given as argument can't be opened"));
    if (!bit_data)
        return(error_out("Error: data base can't be opened"));
    std::getline(bit_data, line);
    while (std::getline(bit_data, line))
        bit_map[line.substr(0, 10)] = atof(line.substr(11).c_str());

    BitcoinExchange bitcoin(&argument, &bit_map);
    bitcoin.converter();

    argument.close();
    bit_data.close();
    return 0;
}