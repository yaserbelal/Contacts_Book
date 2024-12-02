#ifndef CONTACT_BOOK_H
#define CONTACT_BOOK_H
#include "ArrayDS.h"
#include "Person.h"
using namespace std;
class Contact_Book
{
private:
    ArrayDS<Person> contacts;
    void displayPersonInTable(const Person& person, int id) const;
    void printTableLine() const;

public:
    void addContact(const Person& person);
    void deleteContact(int index);
    int findContact(const string& firstName, const string& lastName) const;
    void editContact(const string& firstName, const string& lastName);
    void displayAllContacts() const;
    void displayFavorites() const ;
    Person& getContactAt(int index);
    const Person& getContactAt(int index) const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
    void searchByLastName(const string& lastName) const;
    void searchByClassification(const string& classification) const ;
    void reverseContacts() ;
    void sortContacts() ;
};


#endif // CONTACT_BOOK_H
