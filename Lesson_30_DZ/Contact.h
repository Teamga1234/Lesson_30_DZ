#pragma once
#include <iostream>
#include <string>
using namespace std;

class IContact {
public:
    virtual void show() const = 0;
};

class Person : public IContact {
    string surname;
    string address;
    string phone;

public:
    Person(const string& surname, const string& address, const string& phone)
        : surname(surname), address(address), phone(phone) {}

    void show() const override {
        cout << "Surname: " << surname << endl
            << "Address: " << address << endl
            << "Phone: " << phone << endl;
    }
    string getAddress() const {
        return address;
    }
};

class Colleague : public IContact {
    string organization;
    string address;
    string phone;
    string fax;
    string contactPerson;

public:
    Colleague(const string& organization, const string& address, const string& phone, const string& fax, const string& contactPerson)
        : organization(organization), address(address), phone(phone), fax(fax), contactPerson(contactPerson) {}

    void show() const override {
        cout << "Organization: " << organization << endl
            << "Address: " << address << endl 
            << "Phone: " << phone << endl
            << "Fax: " << fax << endl 
            << "Contact person: " << contactPerson << endl;
    }
    string getAddress() const {
        return address;
    }
};

class Friend : public IContact {
    string surname;
    string address;
    string phone;
    string birthday;

public:
    Friend(const string& surname, const string& address, const string& phone, const string& birthday)
        : surname(surname), address(address), phone(phone), birthday(birthday) {}

    void show() const override {
        cout << "Surname: " << surname << endl 
            << "Address: " << address << endl 
            << "Phone: " << phone << endl 
            << "Birthday: " << birthday << endl;
    }
    string getAddress() const {
        return address;
    }
};
