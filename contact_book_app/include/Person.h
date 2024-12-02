#include <iostream>
#include <string>
using namespace std;
#include "Address.h"
#ifndef PERSON_H
#define PERSON_H
class Person
{
private:
    string firstName;
    string lastName;
    string personClass;
    bool isFavorite;
    static const int MAX_PHONES = 10;
    static const int MAX_EMAILS = 10;
    string phoneNumbers[MAX_PHONES];
    int phoneCount;
    string emails[MAX_EMAILS];
    int emailCount;
    Address address;

public:
    Person();
    ~Person();
    //setter&&getter
    void setFirstName(const string& firstName);
    string getFirstName() const;

    void setLastName(const string& lastName);
    string getLastName() const;

    void setPersonClass(const string& personClass);
    string getPersonClass() const;

    void setIsFavorite(bool isFavorite);
    bool getIsFavorite() const;

    void addPhoneNumber(const string& phoneNumber) ;
    string getPhoneNumber(int index) const;
    void addEmail(const string& email);
    string getEmail(int index) const;
    void setAddress(const Address& address);
    Address getAddress() const;
    int getPhoneCount() const ;
    int getEmailCount() const;

    void inputPerson();
    void displayPerson() const;
};
#endif // PERSON_H
