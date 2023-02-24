
#ifndef EX01_CONTACT_CLASS_HPP
#define EX01_CONTACT_CLASS_HPP

#include <string>
#include <iostream>
# include <iomanip>

using namespace std;

class Contact {
private:
    int					index;
    static string	    list_name[5];
    string			    informations[5];

    enum Field {
        FirstName = 0,
        LastName,
        Nickname,
        PhoneNumber,
        DarkestSecret
    };
public:
    Contact();
    virtual ~Contact();

    bool	set_informations(int index);
    void	display_header();

    void display();
};

#endif //EX01_CONTACT_CLASS_HPP
