#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iomanip>
#include "Address.h"
#include "DynamicArray.h"
using namespace std;

class Person {
private:
    string firstName;
    string lastName;
    string classification;
    DynamicArray<string> phoneNumber;
    DynamicArray<string> email;
    Address address;
    bool isFavorite;
public:
    bool operator==(const Person &a) const {
        return firstName == a.firstName && lastName == a.lastName;
    }

    bool operator!=(const Person &a) const {
        return !(*this == a);
    }

    bool operator<(const Person &a) const {
        if (firstName < a.firstName) return true;
        if (firstName > a.firstName) return false;
        return lastName < a.lastName;
    }

    bool operator>(const Person &a) const {
        return a < *this;
    }

    bool operator<=(const Person &a) const {
        return !(*this > a);
    }

    bool operator>=(const Person &a) const {
        return !(*this < a);
    }

    friend ostream& operator<<(ostream& os, const Person& person);

    Person() : firstName(""), lastName(""), classification(""), phoneNumber(DynamicArray<string>()), email(DynamicArray<string>()), address(), isFavorite(false) {}

    Person(string firstName, string lastName, string classification, DynamicArray<string> phoneNumber, DynamicArray<string> email, Address address, bool isFav) :
    firstName(firstName), lastName(lastName), classification(classification), phoneNumber(phoneNumber), email(email), address(address), isFavorite(isFav) {};

    void setFirstName(string firstName) {this->firstName = firstName;}
    void setLastName(string lastName) {this->lastName = lastName;}
    void setClassification(string Classification) {this->classification = Classification;}
    void setPhoneNumber(DynamicArray<string> phoneNumber) {this->phoneNumber = phoneNumber;}
    void setEmail(DynamicArray<string> email) {this->email = email;}
    void setAddress(Address address) {this->address = address;}
    void setIsFavorite(bool val) {this->isFavorite = val;}

    string getFirstName() {return firstName;}
    string getLastName() {return lastName;}
    string getClassification() {return classification;}
    DynamicArray<string> getPhoneNumber() {return phoneNumber;}
    DynamicArray<string> getEmail() {return email;}
    Address getAddress() {return address;}
    bool getIsFavorite() {return isFavorite;}


    void printPerson() {
        cout << left << setw(14) << "First Name: " << getFirstName() << endl;
        cout << left << setw(14) << "Last Name: " << getLastName() << endl;
        cout << left << setw(14) << "Class: " << getClassification() << endl;
        cout << left << setw(14) << "Favorite: " << (getIsFavorite()? "Yes" : "No") << endl;
        cout << left << setw(14) << "Numbers: " << getPhoneNumber().getFullElements() << endl;
        cout << left << setw(14) << "Emails: " << getEmail().getFullElements() << endl;
        cout << left << setw(14) << "Address: " << getAddress() << endl;
    }
};

ostream& operator<<(ostream& os, Person& person) {
    const int w1 = 10;  // For shorter fields (names, birthdate)
    const int w2 = 22;
    const int w3 = 35;
    os << left
       << "| " << setw(w1) << person.getFirstName()
       << "| " << setw(w1) << person.getLastName()
       << "| " << setw(w1) << person.getClassification()
       << "| " << setw(w1) << (person.getIsFavorite()? "Yes" : "No")
       << "| " << setw(w2) << person.getPhoneNumber().getCuttedElements()
       << "| " << setw(w2) << person.getEmail().getCuttedElements()
       << "| " << setw(w3) << person.getAddress()
       << "| ";

    return os;
}

#endif //PERSON_H
