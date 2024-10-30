#include "Container.h"

int main()
{
    Container container;
    int choice;
    do {
        cout << "\nMenu\n"
            << "1. Add Contact\n"
            << "2. Remove Contact\n"
            << "3. Show All Contacts\n"
            << "4. Find Contact by Address\n"
            << "5. Exit\n"
            << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int type;
            cout << "Select Contact Type: 1. Person 2. Colleague 3. Friend: ";
            cin >> type;
            string surname, organization, address, phone, fax, contactPerson, birthday;

            if (type == 1) { 
                cout << "Enter Surname, Address, Phone: ";
                cin >> surname >> address >> phone;
                container.addContact(new Person(surname, address, phone));
            }
            else if (type == 2) { 
                cout << "Enter Organization, Address, Phone, Fax, Contact Person: ";
                cin >> organization >> address >> phone >> fax >> contactPerson;
                container.addContact(new Colleague(organization, address, phone, fax, contactPerson));
            }
            else if (type == 3) {
                cout << "Enter Surname, Address, Phone, Birthday: ";
                cin >> surname >> address >> phone >> birthday;
                container.addContact(new Friend(surname, address, phone, birthday));
            }
            break;
        }
        case 2: {
            int index;
            cout << "Enter index of contact to remove: ";
            cin >> index;
            container.removeContact(index);
            break;
        }
        case 3: {
            container.showAllContacts();
            break;
        }
        case 4: {
            string address;
            cout << "Enter Address to find: ";
            cin >> address;
            IContact* contact = container.findContactByAddress(address);
            if (contact) {
                contact->show();
            }
            else {
                cout << "Contact not found.\n";
            }
            break;
        }
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);
}