
#include "Contact.hpp"

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
        this->informations[i] = std::string();
}

Contact::~Contact()
{
}

bool Contact::set_informations(int index)
{
    std::string info = "";

    this->index = index;
    for (int i = FirstName; i <= DarkestSecret; i++)
    {
        std::cout << "# " << Contact::list_name[i] << ":\n+";
        getline(std::cin, info);
        while (info == ""){
            std::cout << "Please fill this field" << std::endl;
            getline(std::cin, info);
        }
        this->informations[i] = info;
        info = "";
    }
    std::cout << "# Contact added !" << std::endl;
    return (true);
}

void Contact::display_header()
{
    std::cout << "|" << std::setw(10) << this->index;
    for (int i = FirstName; i <= Nickname; i++)
    {
        std::cout << "|";
        if (this->informations[i].length() > 10)
            std::cout << this->informations[i].substr(0, 9) << ".";
        else
            std::cout << std::setw(10) << this->informations[i];
    }
    std::cout << "|" << std::endl;
}

void Contact::display(void)
{
    std::cout << "# Contact [" << this->index << "]" << std::endl;
    for (int i = FirstName; i <= DarkestSecret; i++)
    {
        std::cout << Contact::list_name[i] << ": ";
        std::cout << this->informations[i] << std::endl;
    }
}
