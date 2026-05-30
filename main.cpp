
#include <iostream>
#include <vector>
#include <string>
#include<fstream>
// A simple structure to hold contact data
struct Contact {
    std::string name;
    std::string phone;
};

// Function prototypes (promises to the compiler)
void addContact(std::vector<Contact>& book);
void displayContacts(const std::vector<Contact>& book);
void searchContact(const std::vector<Contact>& book);
void saveToFile(const std::vector<Contact>& book);
void loadFromFile(std::vector<Contact>& book);

int main() {
    std::vector<Contact> contactBook;
    int choice;

    loadFromFile(contactBook);

    do {
        std::cout << "\n--- CONTACT BOOK ---\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. Display All Contacts\n";
        std::cout << "3.search contact \n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addContact(contactBook);
                break;
            case 2:
                displayContacts(contactBook);
                break;
            case 3:
                searchContact(contactBook);
                break;
            case 4:
                std::cout << "Exiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}

void addContact(std::vector<Contact>& book) {
    Contact newContact;
    std::cout << "Enter Name: ";
    std::cin.ignore(); // Clears the input buffer
    std::getline(std::cin, newContact.name);
    std::cout << "Enter Phone Number: ";
    std::cin >> newContact.phone;
    
    book.push_back(newContact);
    std::cout << "Contact added successfully!\n";
}

void searchContact(const std::vector<Contact>& book) {
    if (book.empty()) {
        std::cout << "The contact book is empty.\n";
        return;
    }

    std::string searchName;
    std::cout << "Enter the name to search for: ";
    std::cin.ignore();
    std::getline(std::cin, searchName);

    bool found = false;
    for (const auto& contact : book) {
        if (contact.name == searchName) {
            std::cout << "\nContact Found!\n";
            std::cout << "Name: " << contact.name << " | Phone: " << contact.phone << "\n";
            found = true;
            break; // Stop looping once found
        }
    }

    if (!found) {
        std::cout << "No contact found with the name '" << searchName << "'.\n";
    }
}

void displayContacts(const std::vector<Contact>& book) {
    if (book.empty()) {
        std::cout << "No contacts found.\n";
        return;
    }
    std::cout << "\n--- All Contacts ---\n";
    for (const auto& contact : book) {
        std::cout << "Name: " << contact.name << " | Phone: " << contact.phone << "\n";
    }
}

void saveToFile(const std::vector<Contact>& book) {
    std::ofstream outFile("contacts.txt"); // Opens or creates the file

    if (!outFile) {
        std::cout << "Error saving data to file!\n";
        return;
    }

    for (const auto& contact : book) {
        // Save name and phone separated by a comma
        outFile << contact.name << "," << contact.phone << "\n";
    }
    outFile.close();
    std::cout << "Contacts successfully saved to contacts.txt!\n";
}

void loadFromFile(std::vector<Contact>& book) {
    std::ifstream inFile("contacts.txt");
    if (!inFile) {
        // If file doesn't exist yet, that's fine (first time running the app)
        return; 
    }

    Contact temp;
    // Read the line up to the comma as the name, and the rest as the phone
    while (std::getline(inFile, temp.name, ',') && std::getline(inFile, temp.phone)) {
        book.push_back(temp);
    }
    inFile.close();
}