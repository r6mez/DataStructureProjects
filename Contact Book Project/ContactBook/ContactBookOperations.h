#ifndef CONTACTBOOKOPERATIONS_H
#define CONTACTBOOKOPERATIONS_H
#include <string>
#include <iostream>
#include <fstream>
#include "Person.h"
#include "DynamicArray.h"
#include "PrintingContactBook.h"
using namespace std;

void addNewContact(DynamicArray<Person> &contactBook) {
    string firstName; cout << "Enter First Name: "; getline(cin, firstName);

    string lastName; cout << "Enter Last Name: "; getline(cin, lastName);

    string classification; cout << "Enter Classification (Family, Friend, Work, Other): "; getline(cin, classification);

    int numOfPhones; cout << "Enter Number of Phone Numbers: "; cin >> numOfPhones;
    while(numOfPhones < 1 || numOfPhones > 3) {
        cout << "Sorry! you must enter at least 1 and at most 3 phone numbers." << endl;
        cout << "Enter Number of Phone Numbers: "; cin >> numOfPhones;
    }

    cin.ignore();
    DynamicArray<string> phones;
    for (int i = 1; i <= numOfPhones; i++) {
        string phoneNumber;
        cout << "[" << i << "]" << "Enter phone number: ";
        getline(cin, phoneNumber);
        phones.append(phoneNumber);
    }

    int numOfEmails; cout << "Enter Number of Emails: "; cin >> numOfEmails;
    while(numOfEmails < 1 || numOfEmails > 3) {
        cout << "Sorry! you must enter at least 1 and at most 3 emails." << endl;
        cout << "Enter Number of emails: "; cin >> numOfPhones;
    }
    cin.ignore();
    DynamicArray<string> emails;
    for (int i = 1; i <= numOfEmails; i++) {
        string email;
        cout << "[" << i << "]" << "Enter email: ";
        getline(cin, email);
        emails.append(email);
    }

    string building; cout << "Enter Building: "; getline(cin, building);
    string street; cout << "Enter Street: "; getline(cin, street);
    string city; cout << "Enter City: "; getline(cin, city);
    string state; cout << "Enter State: "; getline(cin, state);

    string isFavString; cout << "Favorite? [1] Yes [2]No : "; getline(cin, isFavString);
    bool isFav = (isFavString == "1");
    contactBook.append(Person(firstName, lastName, classification, phones, emails, Address(building, street, city, state), isFav));
    cout << "\n Added Successfully! \n";
}

void updateContact(DynamicArray<Person> &contactBook) {
    int index;
    cout << "Enter index to Edit: ";
    cin >> index;
    cin.ignore();

    cout << "For each value press enter to skip or write a value to edit then press enter.\n";

    string firstName; cout << "Enter First Name: "; getline(cin, firstName);
    if(firstName == "") firstName = contactBook[index].getFirstName();

    string lastName; cout << "Enter Last Name: "; getline(cin, lastName);
    if(lastName == "") lastName = contactBook[index].getLastName();

    string classification; cout << "Enter Classification (Family, Friend, Work, Other): "; getline(cin, classification);
    if(classification == "") classification = contactBook[index].getClassification();

    string numOfPhones; cout << "Enter Number of Phone Numbers: "; getline(cin, numOfPhones);
    DynamicArray<string> phones;
    if(numOfPhones == "") {
        phones = contactBook[index].getPhoneNumber();
    } else {
        while(stoi(numOfPhones) < 1 || stoi(numOfPhones) > 3) {
            cout << "Sorry! you must enter at least 1 and at most 3 phone numbers." << endl;
            cout << "Enter Number of Phone Numbers: "; cin >> numOfPhones;
        }
        for (int i = 1; i <= stoi(numOfPhones); i++) {
            string phoneNumber;
            cout << "[" << i << "]" << "Enter phone number: ";
            getline(cin, phoneNumber);
            phones.append(phoneNumber);
        }
    }


    string numOfEmail; cout << "Enter Number of Emails: "; getline(cin, numOfEmail);
    DynamicArray<string> emails;
    if(numOfEmail == "") {
        emails = contactBook[index].getEmail();
    } else {
        while(stoi(numOfEmail) < 1 || stoi(numOfEmail) > 3) {
            cout << "Sorry! you must enter at least 1 and at most 3 emails." << endl;
            cout << "Enter Number of emails: "; cin >> numOfPhones;
        }
        for (int i = 1; i <= stoi(numOfEmail); i++) {
            string email;
            cout << "[" << i << "]" << "Enter email: ";
            getline(cin, email);
            emails.append(email);
        }
    }

    string building; cout << "Enter Building: "; getline(cin, building);
    if(building == "") building = contactBook[index].getAddress().getBuilding();
    string street; cout << "Enter Street: "; getline(cin, street);
    if(street == "") street = contactBook[index].getAddress().getStreet();
    string city; cout << "Enter City: "; getline(cin, city);
    if(city == "") city = contactBook[index].getAddress().getCity();
    string state; cout << "Enter State: "; getline(cin, state);
    if(state == "") state = contactBook[index].getAddress().getState();

    string isFavString; cout << "Favorite? [1] Yes [2]No : "; getline(cin, isFavString);
    bool isFav = (isFavString == "1");
    if(isFavString == "") isFav = contactBook[index].getIsFavorite();

    contactBook[index] = Person(firstName, lastName, classification, phones, emails, Address(building, street, city, state), isFav);
    cout << "\n Updated Successfully! \n";
}

void deleteContact(DynamicArray<Person> &contactBook) {
    int index;
    cout << "Enter index to delete: ";
    cin >> index;
    contactBook.delete_at(index);
    cout << "\n Deleted Successfully! \n";
}

void searchByName(DynamicArray<Person> &contactBook) {
    string firstName, lastName;
    cout << "Enter First and Last Name: ";
    cin >> firstName >> lastName;
    DynamicArray<string> temp;
    int index = contactBook.linear_search(Person(firstName, lastName, "", temp, temp, Address(), true));
    if(index != -1) {
        cout << "Result: \n";
        printLine();
        contactBook[index].printPerson();
        printLine();
    } else {
        cout << "No such Person found!\n";
    }
}

void filterByClassification(DynamicArray<Person> &contactBook) {
    cout << "Enter Classificaton to Filter: ";
    string classification; getline(cin, classification);
    cout << "Result: \n";
    printLine();
    int x = 1;
    for (int i = 0; i < contactBook.getSize(); ++i) {
        if(contactBook[i].getClassification() == classification) {
            cout  << left << "| " << setw(3) << x << contactBook[i] << endl;
            x++;
        }
    }
    printLine();
}

void printFavoriteContacts(DynamicArray<Person> &contactBook) {
    cout << "Result: \n";
    printLine();
    int x = 1;
    for (int i = 0; i < contactBook.getSize(); ++i) {
        if(contactBook[i].getIsFavorite()) {
            cout  << left << "| " << setw(3) << x << contactBook[i] << endl;
            x++;
        }
    }
    printLine();
}

void shareContact(DynamicArray<Person> &contactBook) {
    cout << "Enter contact index to share: ";
    int index; cin >> index;

    string fileName = contactBook[index].getFirstName() + contactBook[index].getLastName() + ".txt";
    ofstream outFile(fileName);
    if (!outFile) {
        cout << "Error opening file for sharing contact" << endl;
        return;
    }

    outFile << left << setw(14) << "First Name: " << contactBook[index].getFirstName() << endl;
    outFile << left << setw(14) << "Last Name: " << contactBook[index].getLastName() << endl;
    outFile << left << setw(14) << "Class: " << contactBook[index].getClassification() << endl;
    outFile << left << setw(14) << "Favorite: " << (contactBook[index].getIsFavorite()? "Yes" : "No") << endl;
    outFile << left << setw(14) << "Numbers: " << contactBook[index].getPhoneNumber().getFullElements() << endl;
    outFile << left << setw(14) << "Emails: " << contactBook[index].getEmail().getFullElements() << endl;
    outFile << left << setw(14) << "Address: " << contactBook[index].getAddress() << endl;

    outFile.close();

    cout << "Contact Saved Succesfully, File name: " << fileName << endl;
}

void saveToFile(DynamicArray<Person> &contactBook) {
    ofstream outFile("contacts.txt");
    if (!outFile) {
        cout << "Error opening file for saving contacts!" << endl;
        return;
    }

    for (int i = 0; i < contactBook.getSize(); ++i) {
        Person person = contactBook[i];

        outFile << person.getFirstName() << "|"
                << person.getLastName() << "|"
                << person.getClassification() << "|";

        DynamicArray<string> phones = person.getPhoneNumber();
        outFile << phones.getSize() << "|";
        for (int j = 0; j < phones.getSize(); ++j) {
            outFile << phones[j];
            if (j != phones.getSize() - 1) outFile << ",";
        }
        outFile << "|";

        DynamicArray<string> emails = person.getEmail();
        outFile << emails.getSize() << "|";
        for (int j = 0; j < emails.getSize(); ++j) {
            outFile << emails[j];
            if (j != emails.getSize() - 1) outFile << ",";
        }
        outFile << "|";

        Address addr = person.getAddress();
        outFile << addr.getBuilding() << "|"
                << addr.getStreet() << "|"
                << addr.getCity() << "|"
                << addr.getState() << "|";

        outFile << (person.getIsFavorite() ? "1" : "0") << endl;
    }

    outFile.close();
    cout << "Contacts saved successfully!" << endl;
}

void loadFromFile(DynamicArray<Person> &contactBook) {
    ifstream inFile("contacts.txt");
    if (!inFile) {
        cout << "Error opening file for loading contacts!" << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string firstName, lastName, classification, phoneStr, emailStr;
        string building, street, city, state, isFavStr;

        getline(ss, firstName, '|');
        getline(ss, lastName, '|');
        getline(ss, classification, '|');

        int numPhones;
        ss >> numPhones;
        ss.ignore(1, '|');
        DynamicArray<string> phones;
        getline(ss, phoneStr, '|');
        stringstream phoneStream(phoneStr);
        for (int i = 0; i < numPhones; ++i) {
            string phone;
            getline(phoneStream, phone, ',');
            phones.append(phone);
        }

        int numEmails;
        ss >> numEmails;
        ss.ignore(1, '|');
        DynamicArray<string> emails;
        getline(ss, emailStr, '|');
        stringstream emailStream(emailStr);
        for (int i = 0; i < numEmails; ++i) {
            string email;
            getline(emailStream, email, ',');
            emails.append(email);
        }

        getline(ss, building, '|');
        getline(ss, street, '|');
        getline(ss, city, '|');
        getline(ss, state, '|');

        getline(ss, isFavStr, '|');
        bool isFav = (isFavStr == "1");

        contactBook.append(Person(firstName, lastName, classification, phones, emails, Address(building, street, city, state), isFav));
    }

    inFile.close();
    cout << contactBook.getSize() << " Contacts loaded successfully!";
}


#endif //CONTACTBOOKOPERATIONS_H
