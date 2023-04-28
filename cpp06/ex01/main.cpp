#include <iostream>

struct Data
{
    std::string city;
    int         population;
};

//uintptr_t : unsigned integer type capable of holding a pointer to void
uintptr_t serialize(Data *ptr) {
    // reinterpret cast permet de recast même des class qui n'ont rien à voir à notre risque et peril
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}

int main(){

    Data *data_test = new Data;

    data_test->city = "Paris";
    data_test->population = 9000000;

    //data_test pointer de type Data serialized into uintptr_t then back into Data type
    std::cout << "City: " << data_test->city << std::endl;
    std::cout << "City: " << serialize( data_test ) << std::endl;
    std::cout << "City: " << deserialize( serialize( data_test ) )->city << std::endl;
    std::cout << "Population: " << deserialize( serialize( data_test ) )->population << std::endl;
    //checking permanence of the change
    std::cout << "City: " << data_test->city << std::endl;
    std::cout << "Population: " << data_test->population << std::endl;

    delete data_test;
    return 0;
}

