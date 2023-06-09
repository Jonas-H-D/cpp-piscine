#include "BitcoinExchange.hpp"

int	error_m(std::string str){
	std::cout << str << std::endl;
	return (1);
}

int	main(int argc, char **argv){
	std::string		line;
	std::ifstream	input;
	std::ifstream	data;
	myMap			data_map;

	std::cout.precision(7);
	if (argc != 2)
		return (error_m( "Error: launch program with input data as argument: ./btc <file>"));
	input.open(argv[1], std::ifstream::in);
	data.open("./data.csv", std::ifstream::in);
	if (!data)
		return (error_m("Error: could not open data file."));
	if (!input)
		return (error_m("Error: could not open input file."));
	while (std::getline(data, line))
		data_map[line.substr(0, 10)] = atof(line.substr(11).c_str());

	BitcoinExchange	btc(&input, &data_map);
    BitcoinExchange btcCopy(btc);
    BitcoinExchange btcCopy2;
    btcCopy2 = btc;
    btcCopy2.converter();

	input.close();
	data.close();
	
	return 0;
}
