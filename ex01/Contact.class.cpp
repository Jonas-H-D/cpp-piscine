//
// Created by Jonas Hermon-Duc on 10/02/2023.
//
#include <string>
#include "Contact.class.hpp"

using namespace std;

Contact::Contact() {
    firstName = "Default";
    lastName = "Default";
    nickname = "Default";
    phoneNumber = "0XXXX";
    darkestSecret = "NOYB";
}

Contact::Contact(string fName, string lName, string niName, string phone, string secret) {
    firstName = fName;
    lastName = lName;
    nickname = niName;
    phoneNumber = phone;
    darkestSecret = secret;
}

Contact::Contact(const Contact& other) {
    firstName = other.firstName;
    lastName = other.lastName;
    nickname = other.nickname;
    phoneNumber = other.phoneNumber;
    darkestSecret = other.darkestSecret;
}

string Contact::getFirstName() {
    return firstName;
}

string Contact::getLastName() {
    return lastName;
}

string Contact::getNickname() {
    return nickname;
}
string Contact::getPhoneNumber() {
    return phoneNumber;
}
string Contact::getDarkestSecret() {
    return darkestSecret;
}

bool checkName(string name){
    if (name == "") {
        return false;
    }
    char c = name[0];
    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
        return false;
    }
    return true;
}
bool Contact::setLastName(string name) {
    if (checkName(name)) {
        lastName = name;
        return true;
    }
    return false;
}

bool Contact::setFirstName(string name) {
    if (checkName(name)) {
        firstName = name;
        return true;
    }
    return false;
}

bool Contact::setNickname(string name) {
    if (checkName(name)) {
        nickname = name;
        return true;
    }
    return false;
}

bool Contact::setPhoneNumber(string phone) {
    if (phone == "") {
        return false;
    }
    int i;
    int n = phone.length();
    char c;
    bool found = false;
    for (i = 0; i < n && found == false; i++) {
        c = phone.at(i);
        if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
            found = true;
        }
    }
    if (found) {
        return false;
    }
    phoneNumber = phone;
    return true;
}

bool Contact::setDarkestSecret(string name) {
    if (name == "") {
        return false;
    }
    darkestSecret = name;
    return true;
}
