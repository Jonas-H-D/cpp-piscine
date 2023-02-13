//
// Created by Jonas Hermon-Duc on 10/02/2023.
//

#ifndef EX01_CONTACT_CLASS_HPP
#define EX01_CONTACT_CLASS_HPP

#include <string>
using namespace std;

class Contact {
    string firstName;
    string lastName;
    string nickname;
    string phoneNumber;
    string darkestSecret;
public:
    Contact();
    Contact(string, string, string, string, string);
    Contact(const Contact&);

    string getFirstName();
    string getLastName();
    string getNickname();
    string getDarkestSecret();
    string getPhoneNumber();
    bool setFirstName(string);
    bool setLastName(string);
    bool setNickname(string);
    bool setDarkestSecret(string);
    bool setPhoneNumber(string);
};

#endif //EX01_CONTACT_CLASS_HPP
