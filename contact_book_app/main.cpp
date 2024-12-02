#include <iostream>
#include "Contact_Book.h"
#include <iomanip>
using namespace std;

void displayMenu()
{
cout << "\033[35m\n--- Contact Book Menu ---\033[0m\n";
    cout << "1. Add Contact\n";
    cout << "2. Delete Contact\n";
    cout << "3. Update Contact\n";
    cout << "4. Find Contact\n";
    cout << "5. Search by Last Name\n";
    cout << "6. Search by Classification\n";
    cout << "7. Display All Contacts\n";
    cout << "8. Display Favorite Contacts\n";
    cout << "9. Save Contacts to File\n";
    cout << "10.Load Contacts from File\n";
    cout << "11 Reverse Contacts\n";
    cout << "12. Sort Contacts\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}
void handleAddContact(Contact_Book& contactBook)
{
    Person person;
    person.inputPerson();
    contactBook.addContact(person);
    cout << "\033[32mContact added successfully ^---^.\033[0m\n";
    cout << "-----------------------------------\n";
}

void handleDeleteContact(Contact_Book& contactBook)
{
    int index;
    cout << "Enter the index of the contact to delete: ";
    cin >> index;
    cin.ignore();
    contactBook.deleteContact(index);
    cout << "\033[32mContact deleted successfully ^---^.\033[0m\n";
    cout << "-----------------------------------\n";
}

void handleFindContact(Contact_Book& contactBook)
{
    string firstName, lastName;
    cout << "Enter the first name of the contact to find: ";
    getline(cin, firstName);
    cout << "Enter the last name of the contact to find: ";
    getline(cin, lastName);

    int index = contactBook.findContact(firstName, lastName);
    if (index != -1)
    {
        cout << "Contact found at index " << index << ":\n";
        contactBook.getContactAt(index).
        displayPerson();
        cout << "-----------------------------------\n";
    }
    else
    {
        cout << "Contact not found.\n";
        cout << "-----------------------------------\n";
    }
}

void handleEditContact(Contact_Book& contactBook)
{
    string firstName, lastName;
    cout << "============================\n";
    cout << "Enter the first name of the contact to edit: ";
    getline(cin, firstName);
    cout << "Enter the last name of the contact to edit: ";
    getline(cin, lastName);

    contactBook.editContact(firstName, lastName);
    cout << "============================\n";
    cout << "\033[32mContact edited successfully ^---^.\033[0m\n";
    cout << "============================\n";
}

void handleDisplayAllContacts(Contact_Book& contactBook)
{
    contactBook.displayAllContacts();
}

void handleDisplayFavorites(Contact_Book& contactBook)
{
    contactBook.displayFavorites();
}

void handleSearchByLastName(Contact_Book& contactBook)
{
    string lastName;
    cout << "Enter last name to search: ";
    getline(cin, lastName);
    contactBook.searchByLastName(lastName);
}

void handleSearchByClassification(Contact_Book& contactBook)
{
    string classification;
    cout << "Enter classification to search (e.g., Friend, Work, Family): ";
    getline(cin, classification);
    contactBook.searchByClassification(classification);
}

void handleSaveContacts(Contact_Book& contactBook)
{
    string filename;
    cout << "Enter filename to save contacts: ";
    getline(cin, filename);
    contactBook.saveToFile(filename);
}

void handleLoadContacts(Contact_Book& contactBook)
{
    string filename;
    cout << "Enter filename to load contacts: ";
    getline(cin, filename);
    contactBook.loadFromFile(filename);
}
void handleReverseContacts(Contact_Book& contactBook)
{
    contactBook.reverseContacts();
    cout << "\033[32mContacts reversed successfully ^---^.\033[0m\n";
    cout << "-----------------------------------\n";
}

void handleSortContacts(Contact_Book& contactBook)
{
    contactBook.sortContacts();
    cout << "\033[32mContacts sorted successfully.\033[0m\n";
}


int main()
{
    Contact_Book contactBook;
    int choice;

    do
    {
        displayMenu();
        cin >> choice;
        cin.ignore();
        system("cls");

        switch (choice)
        {
        case 1:
            handleAddContact(contactBook);
            break;
        case 2:
            handleDeleteContact(contactBook);
            break;
        case 3:
            handleEditContact(contactBook);
            break;
        case 4:
            handleFindContact(contactBook);

            break;
        case 5:
            handleSearchByLastName(contactBook);
            break;
        case 6:
            handleSearchByClassification(contactBook);
            break;

        case 7:
            handleDisplayAllContacts(contactBook);
            break;
        case 8:
            handleDisplayFavorites(contactBook);
            break;
        case 9:
            handleSaveContacts(contactBook);
            break;
        case 10:
            handleLoadContacts(contactBook);
            break;
        case 11:
            handleReverseContacts(contactBook);
            break;
        case 12:
            handleSortContacts(contactBook);
            break;

        case 0:
            cout << "\033[35mExiting ^...^\033[0m\n";
            break;
        default:
            cout << "\033[31mInvalid choice, Please try again.\033[0m\n";
            break;
        }
    }
    while (choice != 0);

    return 0;
}
