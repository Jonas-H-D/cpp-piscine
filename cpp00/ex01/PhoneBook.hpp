
#ifndef EX01_PHONEBOOK_HPP
#define EX01_PHONEBOOK_HPP
#include <list>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include "Contact.hpp"

class PhoneBook {
private:
    Contact	contacts[8];
    int		nr;
public:
    PhoneBook();
    ~PhoneBook();

    void    start_display(void);
    void    search_display(void);
    void	add_contact(void);
    void	search_contact(void);
};
#endif
