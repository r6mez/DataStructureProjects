#ifndef PRINTING_H
#define PRINTING_H
#include <iostream>
using namespace std;

void printHello(const DynamicArray<Person> &contacts) {
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t Ramez's Contact Book: " << contacts.getSize() << " Contacts" << "\n";
}

void printHeader() {
    const int w1 = 10;
    const int w2 = 22;
    const int w3 = 35;
    cout << left
         << "| " << setw(3) << "i"
         << "| " << setw(w1) << "FirstName"
         << "| " << setw(w1) << "LastName"
         << "| " << setw(w1) << "Class"
         << "| " << setw(w1) << "Favorite"
         << "| " << setw(w2) << "Phone Numbers"
         << "| " << setw(w2) << "Emails"
         << "| " << setw(w3) << "Address"
         << "| \n";
}

void printLine() {
    cout << "+-----------------------------------------------------------------------------------------------------------------------------------------+\n";
}

void printOptions() {
    cout << "Options: " << endl;
    cout << "[1] Add a new contact" << endl;
    cout << "[2] Update contact Information" << endl;
    cout << "[3] Delete a contact" << endl;
    cout << "[4] Sort by name" << endl;
    cout << "[5] Reverse contact book" << endl;
    cout << "[6] Search by name" << endl;
    cout << "[7] Filter by classification" << endl;
    cout << "[8] Print favorite contacts" << endl;
    cout << "[9] Share contact" << endl;
    cout << "[10] Save to file" << endl;
    cout << "[11] Load from file" << endl;
    cout << "[12] Exit" << endl;
    printLine();
    cout << "Select option: ";
}

void printContactBook(DynamicArray<Person> &contacts) {
    cout << endl;
    printLine();
    printHello(contacts);
    printLine();
    printHeader();
    printLine();
    contacts.displayList();
    printLine();
}

void printEnd() {
    printLine();
    cout << "This project was made with love by \"Ramez Medhat\" \n";
    cout << "Thank you for using it. \n";
    printLine();
}
#endif //PRINTING_H
