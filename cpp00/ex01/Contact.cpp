
#include "Contact.hpp"

using namespace std;

std::string Contact::list_name[5] = {
        "First Name",
        "Last Name",
        "Nickname",
        "Phone Number",
        "Darkest Secret",
};

Contact::Contact()
{
    for (int i = FirstName; i <= DarkestSecret; i++)
        this->informations[i] = string();
}

Contact::~Contact()
{
}

bool Contact::set_informations(int index)
{
    string info = "";

    this->index = index;
    for (int i = FirstName; i <= DarkestSecret; i++)
    {
        cout << "# " << Contact::list_name[i] << ":\n+";
        getline(cin, info);
        while (info == ""){
            cout << "Please fill this field" << endl;
            getline(cin, info);
        }
        this->informations[i] = info;
        info = "";
    }
    cout << "# Contact added !" << endl;
    return (true);
}

void Contact::display_header()
{
    cout << "|" << setw(10) << this->index;
    for (int i = FirstName; i <= Nickname; i++)
    {
        cout << "|";
        if (this->informations[i].length() > 10)
            cout << this->informations[i].substr(0, 9) << ".";
        else
            cout << setw(10) << this->informations[i];
    }
    cout << "|" << endl;
}

void Contact::display(void)
{
    cout << "# Contact [" << this->index << "]" << endl;
    for (int i = FirstName; i <= DarkestSecret; i++)
    {
        cout << Contact::list_name[i] << ": ";
        cout << this->informations[i] << endl;
    }
}
