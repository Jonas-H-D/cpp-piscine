
#ifndef EX01_CONTACT_HPP
#define EX01_CONTACT_HPP

#include <string>
#include <iostream>
# include <iomanip>

class Contact {
private:
    int					index;
    static std::string	    list_name[5];
    std::string			    informations[5];

    enum Field {
        FirstName = 0,
        LastName,
        Nickname,
        PhoneNumber,
        DarkestSecret
    };
public:
    Contact();
    ~Contact();

    bool	set_informations(int index);
    void	display_header();

    void display();
};

#endif
