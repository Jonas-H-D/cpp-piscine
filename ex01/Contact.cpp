//
// Created by Jonas Hermon-Duc on 10/02/2023.
//
#include "Contact.hpp"

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
void Contact::setLastName() {
    string info;

    cout << "Last Name: ";
    getline(cin, info);
    if (checkName(info)) {
        lastName = info;
    }
    else {
        cout << "Non valid Name" << endl;
        setLastName();
    }
}

void Contact::setFirstName() {
    string info;

    cout << "First Name: ";
    getline(cin, info);
    if (checkName(info)) {
        firstName = info;
    }
    else {
        cout << "Non valid Name" << endl;
        setFirstName();
    }
}

void Contact::setNickname() {
    string info;

    cout << "Nickname: ";
    getline(cin, info);
    if (checkName(info)) {
        nickname = info;
    }
    else {
        cout << "Non valid Name" << endl;
        setNickname();
    }
}
bool checkNumber(string phone){
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
    return true;
}

void Contact::setPhoneNumber() {
    string info;

    cout << "PhoneNumber: ";
    getline(cin, info);
    if (checkNumber(info)) {
        phoneNumber = info;
    }
    else {
        cout << "Non valid Number" << endl;
        setPhoneNumber();
    }
}

void Contact::setDarkestSecret() {
    string info;

    cout << "Darkest secret: ";
    getline(cin, info);
    if (info != "") {
        darkestSecret = info;
    }
    else {
        cout << "Can't be empty" << endl;
        setDarkestSecret();
    }
}
