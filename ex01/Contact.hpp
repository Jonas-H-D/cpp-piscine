//
// Created by Jonas Hermon-Duc on 10/02/2023.
//
#ifndef EX01_CONTACT_CLASS_HPP
#define EX01_CONTACT_CLASS_HPP

#include <string>
#include <iostream>

using namespace std;

class Contact {
public:
    string firstName;
    string lastName;
    string nickname;
    string phoneNumber;
    string darkestSecret;
    Contact();
    Contact(string, string, string, string, string);
    Contact(const Contact&);

    string getFirstName();
    string getLastName();
    string getNickname();
    string getDarkestSecret();
    string getPhoneNumber();
    void setFirstName();
    void setLastName();
    void setNickname();
    void setDarkestSecret();
    void setPhoneNumber();
};

#endif //EX01_CONTACT_CLASS_HPP
