
#include "PhoneBook.hpp"
#include <limits>

using namespace std;

PhoneBook::PhoneBook() {
    this->nr = 0;
}

PhoneBook::~PhoneBook() {

}

void PhoneBook::start_display(void) {
    cout << "################PHONEBOOK####################" << endl;
    cout << "Enter your command (ADD, SEARCH, EXIT)" << endl;
    cout << "command >>>>> ";
}

void PhoneBook::search_display(void) {
    cout << "#############################################" << endl;
    cout << "|     Index|First Name| Last Name|  Nickname|"<< endl;
    for (int i = 0; i < this->nr && i < 8 + 1; i++)
        this->contacts[i].display_header();
    cout << "|-------------------------------------------|" << endl;
}

void PhoneBook::add_contact(void)
{
    if (this->nr == 8) {
        cout << "# The directory is full, Making space !" << endl;
        this->contacts[this->nr - 1].set_informations(this->nr -1);
    }
    else if (this->contacts[this->nr].set_informations(this->nr))
        this->nr++;
}

void PhoneBook::search_contact(void)
{
    int	index;

    if (this->nr == 0)
        cout << "# Add a contact before searching !" << endl;
    else
    {
        this->search_display();
        cout << "# Enter Index to display\n~";
        while (!(cin >> index) || (index < 0 || index > this->nr -1))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "# Invalid Index\n~";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        this->contacts[index].display();
    }
}

