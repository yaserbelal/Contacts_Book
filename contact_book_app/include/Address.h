#include <iostream>
#include <string>
using namespace std;
#ifndef ADDRESS_H
#define ADDRESS_H
class Address
{
private:
    int streetNum;
    string streetName;
    string town;
    string state;
public:
    Address();
    ~Address();
    // setter&&getter
    void setStreetNum(const int& streetNum);
    int getStreetNum() const;
    void setStreetName(const string& streetName);
    string getStreetName() const;
    void setTown(const string& town);
    string getTown() const;
    void setState(const string& town);
    string getState() const;


    void inputAddress();
    void displayAddress() const;
};


#endif // ADDRESS_H
