#include "Address.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
Address::Address() : streetNum(0), streetName(""), town(""), state("") {}
Address::~Address() {}
void Address::setStreetNum(const int& streetNum) {
    this->streetNum = streetNum;
}
int Address::getStreetNum() const {
    return streetNum;
}
void Address::setStreetName(const string& streetName) {
    this->streetName = streetName;
}
string Address::getStreetName() const {
    return streetName;
}
void Address::setTown(const string& town) {
    this->town = town;
}
string Address::getTown() const {
    return town;
}
void Address::setState(const string& state) {
    this->state = state;
}

string Address::getState() const {
    return state;
}
void Address::inputAddress() {
    cout << "\033[35m\n::Enter Address Details::\033[0m" << endl;

    cout << left << setw(15) << "Street Number:";
    cin >> streetNum;
    cin.ignore();

    cout << left << setw(15) << "Street Name:";
    getline(cin, streetName);

    cout << left << setw(15) << "Town:";
    getline(cin, town);

    cout << left << setw(15) << "State:";
    getline(cin, state);
}
void Address::displayAddress() const {

    cout << "Street Number: " << streetNum << ", Street Name: " << streetName
         << ", Town: " << town << ", State: " << state << endl;
}
