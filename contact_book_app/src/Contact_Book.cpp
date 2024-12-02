#include "Contact_Book.h"
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;
void Contact_Book::addContact(const Person& person) {
    contacts.add(person);
}
void Contact_Book::deleteContact(int index) {
    contacts.Delete(index);
}

int Contact_Book::findContact(const string& firstName, const string& lastName) const {
    for (int i = 0; i < contacts.getSize(); ++i) {
        if (contacts.get(i).getFirstName() == firstName && contacts.get(i).getLastName() == lastName) {
            return i;
        }
    }
    return -1;
}

void Contact_Book::editContact(const string& firstName, const string& lastName) {
    int index = findContact(firstName, lastName);
    if (index != -1) {
        cout << "Modify Contact Details:\n";
        contacts[index].inputPerson();
    } else {
        cout << "Contact not found.\n";
    }
}

void Contact_Book::printTableLine() const {
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
}

void Contact_Book::displayAllContacts() const {
    printTableLine();
        cout << "\033[1;35m";
    cout << left
         << setw(5) << "ID"
         << setw(15) << "FName"
         << setw(15) << "LName"
         << setw(20) << "Classification"
         << setw(10) << "Fav"
         << setw(25) << "Address"
         << setw(25) << "Phone Num"
         << setw(25) << "Email"
         << "\033[0m\n";
    printTableLine();

    for (int i = 0; i < contacts.getSize(); ++i) {
        displayPersonInTable(contacts[i], i + 1);
        printTableLine();
    }
}

void Contact_Book::displayPersonInTable(const Person& person, int id) const {
cout << left
     << setw(5) << id
     << setw(15) << person.getFirstName()
     << setw(15) << person.getLastName()
     << setw(20) << person.getPersonClass()
     << setw(10) << (person.getIsFavorite() ? "Yes" : "No")
     << setw(25) << (to_string(person.getAddress().getStreetNum()) + ", " +
                     person.getAddress().getStreetName() + ", " +
                     person.getAddress().getTown() + ", " +
                     person.getAddress().getState())
     << setw(25) << person.getPhoneNumber(0)
     << setw(25) << person.getEmail(0)
     << "\n";
}

Person& Contact_Book::getContactAt(int index) {
    return contacts.get(index);
}

const Person& Contact_Book::getContactAt(int index) const {
    return contacts.get(index);
}
void Contact_Book::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (int i = 0; i < contacts.getSize(); ++i) {
            const Person& person = contacts[i];
            outFile << person.getFirstName() << "|"
                    << person.getLastName() << "|"
                    << person.getPersonClass() << "|"
                    << (person.getIsFavorite() ? "Yes" : "No") << "|"
                    << person.getAddress().getStreetNum() << ", "
                    << person.getAddress().getStreetName() << ", "
                    << person.getAddress().getTown() << ", "
                    << person.getAddress().getState() << "|";

            for (int j = 0; j < person.getPhoneCount(); ++j) {
                outFile << person.getPhoneNumber(j);
                if (j < person.getPhoneCount() - 1) outFile << ",";
            }
            outFile << "|";

            for (int j = 0; j < person.getEmailCount(); ++j) {
                outFile << person.getEmail(j);
                if (j < person.getEmailCount() - 1) outFile << ",";
            }
            outFile << "\n";
        }
        outFile.close();
        cout << "\033[32mContacts saved to file successfully.\033[0m\n";
    } else {
        cerr << "Failed to open file for saving.\n";
    }
}
void Contact_Book::loadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        contacts.clear();
        string line;
        while (getline(inFile, line)) {
            Person person;
            Address address;
            stringstream ss(line);
            string segment;

            getline(ss, segment, '|');
            person.setFirstName(segment);

            getline(ss, segment, '|');
            person.setLastName(segment);

            getline(ss, segment, '|');
            person.setPersonClass(segment);

            getline(ss, segment, '|');
            person.setIsFavorite(segment == "Yes");

            getline(ss, segment, '|');
            stringstream addressStream(segment);
            string addrPart;
            getline(addressStream, addrPart, ',');
            address.setStreetNum(stoi(addrPart));
            getline(addressStream, addrPart, ',');
            address.setStreetName(addrPart);
            getline(addressStream, addrPart, ',');
            address.setTown(addrPart);
            getline(addressStream, addrPart);
            address.setState(addrPart);
            person.setAddress(address);

            getline(ss, segment, '|');
            stringstream phoneStream(segment);
            while (getline(phoneStream, addrPart, ',')) {
                person.addPhoneNumber(addrPart);
            }

            getline(ss, segment, '|');
            stringstream emailStream(segment);
            while (getline(emailStream, addrPart, ',')) {
                person.addEmail(addrPart);
            }

            contacts.add(person);
            cout << "Loaded Contact: " << person.getFirstName() << " " << person.getLastName() << "\n";
        }
        inFile.close();
        cout << "\033[32mContacts loaded from file successfully.\033[0m\n";
        displayAllContacts();
    } else {
        cerr << "Failed to open file for loading.\n";
    }
}
void Contact_Book::displayFavorites() const {
    printTableLine();
    cout << "|" << left
         << setw(5) << "ID"
         << "|" << setw(15) << "FName"
         << "|" << setw(15) << "LName"
         << "|" << setw(20) << "Classification"
         << "|" << setw(10) << "Fav"
         << "|" << setw(25) << "Address"
         << "|" << setw(25) << "Phone Num"
         << "|" << setw(25) << "Email"
         << "|\n";
    printTableLine();

    bool found = false;
    for (int i = 0; i < contacts.getSize(); ++i) {
        const Person& person = contacts[i];
        if (person.getIsFavorite()) {
            displayPersonInTable(person, i + 1);
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No favorite contacts found.\n";
    }
    printTableLine();
}
void Contact_Book::searchByLastName(const string& lastName) const {
    printTableLine();
    bool found = false;

    for (int i = 0; i < contacts.getSize(); ++i) {
        if (contacts.get(i).getLastName() == lastName) {
            displayPersonInTable(contacts[i], i + 1);
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No contacts found with the last name '" << lastName << "'.\n";
    }
    printTableLine();
}
void Contact_Book::searchByClassification(const string& classification) const {
    printTableLine();
    bool found = false;

    for (int i = 0; i < contacts.getSize(); ++i) {
        if (contacts.get(i).getPersonClass() == classification) {
            displayPersonInTable(contacts[i], i + 1);
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No contacts found with the classification '" << classification << "'.\n";
    }
    printTableLine();
}
void Contact_Book::reverseContacts() {
    int left = 0;
    int right = contacts.getSize() - 1;
    while (left < right) {
        swap(contacts.get(left), contacts.get(right));
        left++;
        right--;
    }
}
    void Contact_Book:: sortContacts() {
        for (int i = 0; i < contacts.getSize() - 1; i++) {
            for (int j = 0; j < contacts.getSize() - i - 1; j++) {
                if (contacts.get(j).getFirstName() > contacts.get(j + 1).getFirstName()) {
                    swap(contacts.get(j), contacts.get(j + 1));
                }
            }
        }
        cout << "Contacts sorted by first name.\n";
    }


