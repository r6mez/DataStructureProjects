#include <iostream>
#include <ostream>
#include "ContactBookOperations.h"
#include "DynamicArray.h"
#include "Person.h"
#include "PrintingContactBook.h"
using namespace std;

int main() {
    DynamicArray<Person> contactBook;

    printContactBook(contactBook);

    while (true) {
        printOptions();
        int option; cin >> option;
        cin.ignore();
        if (option == 1) {
            // add
            addNewContact(contactBook);
            printContactBook(contactBook);
        } else if (option == 2) {
            // Update
            updateContact(contactBook);
            printContactBook(contactBook);
        } else if (option == 3) {
            // Remove
            deleteContact(contactBook);
            printContactBook(contactBook);
        } else if (option == 4) {
            // sort by Name
            contactBook.mergeSort();
            printContactBook(contactBook);
        } else if (option == 5) {
            contactBook.reverse();
            printContactBook(contactBook);
        } else if (option == 6) {
            // search by name
            searchByName(contactBook);
        } else if (option == 7) {
            // Filter by classification
            filterByClassification(contactBook);
        } else if (option == 8) {
            // Print favorite contacts
            printFavoriteContacts(contactBook);
        } else if (option == 9) {
            // Share contact
            shareContact(contactBook);
        } else if(option == 10) {
            // Save to file
            saveToFile(contactBook);
        } else if (option == 11) {
            // load from file
            loadFromFile(contactBook);
            printContactBook(contactBook);
        } else if (option == 12) {
            // exit
            printEnd();
            break;
        } else {
            cout << "Please enter a valid option!\n";
        }
    }
    return 0;
}
