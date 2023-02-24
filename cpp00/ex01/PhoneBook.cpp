
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    this->nr = 0;
}

PhoneBook::~PhoneBook() {

}

void PhoneBook::start_display(void) {
    std::cout << "################PHONEBOOK####################" << std::endl;
    std::cout << "Enter your command (ADD, SEARCH, EXIT)" << std::endl;
    std::cout << "command >>>>> ";
}

void PhoneBook::search_display(void) {
    std::cout << "#############################################" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|"<< std::endl;
    for (int i = 0; i < this->nr && i < 8 + 1; i++)
        this->contacts[i].display_header();
    std::cout << "|-------------------------------------------|" << std::endl;
}

void PhoneBook::add_contact(void)
{
    if (this->nr == 8) {
        std::cout << "# The directory is full, Making space !" << std::endl;
        this->contacts[this->nr - 1].set_informations(this->nr -1);
    }
    else if (this->contacts[this->nr].set_informations(this->nr))
        this->nr++;
}

void PhoneBook::search_contact(void)
{
    int	index;

    if (this->nr == 0)
        std::cout << "# Add a contact before searching !" << std::endl;
    else
    {
        this->search_display();
        std::cout << "# Enter Index to display\n~";
        while (!(std::cin >> index) || (index < 0 || index > this->nr -1))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "# Invalid Index\n~";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        this->contacts[index].display();
    }
}

