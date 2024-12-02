#include "Person.h"
#include <iostream>
#include <regex>
#include <iomanip>
Person::Person() : firstName(""), lastName(""), personClass(""), isFavorite(false), phoneCount(0), emailCount(0) {}
Person::~Person() {}

void Person::setFirstName(const string& firstName) {
    this->firstName = firstName;
}

string Person::getFirstName() const {
    return firstName;
}

void Person::setLastName(const string& lastName) {
    this->lastName = lastName;
}

string Person::getLastName() const {
    return lastName;
}

void Person::setPersonClass(const string& personClass) {
    this->personClass = personClass;
}

string Person::getPersonClass() const {
    return personClass;
}

string Person::getPhoneNumber(int index) const {
    if (index >= 0 && index < phoneCount) {
        return phoneNumbers[index];
    } else {
        return "\033[31mInvalid index!\033[0m";
    }
}

void Person::setIsFavorite(bool isFavorite) {
    this->isFavorite = isFavorite;
}

bool Person::getIsFavorite() const {
    return isFavorite;
}

int Person::getPhoneCount() const {
    return phoneCount;
}

int Person::getEmailCount() const {
    return emailCount;
}

void Person::addPhoneNumber(const string& phoneNumber) {
    if (phoneCount < MAX_PHONES) {
        regex phonePattern("^\\+20.*$");
        if (regex_match(phoneNumber, phonePattern)) {
            phoneNumbers[phoneCount++] = phoneNumber;
        } else {
            cout << "Invalid phone number! It must start with +20.\n";
        }
    } else {
        cout << "Max number of phone numbers reached!\n";
    }
}

void Person::addEmail(const string& email) {
    if (emailCount < MAX_EMAILS) {
        regex emailPattern("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");
        if (regex_match(email, emailPattern)) {
            emails[emailCount++] = email;
        } else {
            cout << "Invalid email address! It must contain '@'.\n";
        }
    } else {
        cout << "Max number of emails reached!\n";
    }
}

string Person::getEmail(int index) const {
    if (index >= 0 && index < emailCount) {
        return emails[index];
    } else {
        return "\033[31mInvalid index!\033[0m";
    }
}

void Person::setAddress(const Address& address) {
    this->address = address;
}

Address Person::getAddress() const {
    return address;
}

void Person::inputPerson() {
    cout << "\033[35m--- Add a New Contact ---\033[0m" << endl;

    cout << left << setw(15) << "Fn:";
    getline(cin, firstName);

    cout << left << setw(15) << "Ln:";
    getline(cin, lastName);

    cout << left << setw(15) << "Class(Friend ,work ,family ,other): ";
    getline(cin, personClass);

    int fav;
    cout << left << setw(15) << "Set as Fav: (press 1 (fav)or 0 (Not)):";
    cin >> fav;
    isFavorite = (fav == 1);

    cout << left << setw(15) << "How many numbers:?!";
    cin >> phoneCount;
    cin.ignore();

    for (int i = 0; i < phoneCount; ++i) {
        string phoneNumber;
        while (true) {
            cout << left << setw(15) << "Phone #" << (i + 1) << ":";
            getline(cin, phoneNumber);
            regex phonePattern("^\\+20.*$");
            if (regex_match(phoneNumber, phonePattern)) {
                phoneNumbers[i] = phoneNumber;
                break;
            } else {
                cout << "\033[31mInvalid phone number! It must start with +20. Please enter again.\033[0m\n";
            }
        }
    }

    cout << left << setw(15) << "How many mails:?!";
    cin >> emailCount;
    cin.ignore();

    for (int i = 0; i < emailCount; ++i) {
        string email;
        while (true) {
            cout << left << setw(15) << "Email #" << (i + 1) << ":";
            getline(cin, email);
            regex emailPattern("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");
            if (regex_match(email, emailPattern)) {
                emails[i] = email;
                break;
            } else {
                cout << "\033[31mInvalid email address! It must contain '@'. Please enter again.\033[0m\n";
            }
        }
    }

    address.inputAddress();
}

void Person::displayPerson() const {
    cout << "Fn: " << firstName << "\nLn: " << lastName << endl;
    cout << "Class: " << personClass << endl;
    cout << "Favorite: " << (isFavorite ? "Yes" : "No") << endl;

    for (int i = 0; i < phoneCount; ++i) {
        cout << "Phone #" << (i + 1) << ": " << phoneNumbers[i] << endl;
    }

    for (int i = 0; i < emailCount; ++i) {
        cout << "Email #" << (i + 1) << ": " << emails[i] << endl;
    }

    address.displayAddress();
}
