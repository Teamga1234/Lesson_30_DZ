#pragma once
#include "Contact.h"
#include <vector>
class Container
{
	vector<IContact*> contacts;
public:
	void addContact(IContact* a)
	{
		contacts.push_back(a);
	}
	~Container() {  
		for (IContact* contact : contacts) {
			delete contact; 
		}
	}
    void removeContact(int index) {
        if (index >= 0 && index < contacts.size()) {
            delete contacts[index];
            contacts.erase(contacts.begin() + index);
        }
    }

    void showAllContacts() const {
        for (const auto& contact : contacts) {
            contact->show();
        }
    }

    
    IContact* findContactByAddress(const string& address) const {
        for (const auto& contact : contacts) {
            Person* person = dynamic_cast<Person*>(contact);
            if (person->getAddress() == address) {
                return person;
            }
        }
        return nullptr;
    }

};

