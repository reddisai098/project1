
#include <iostream>
#include <vector>
#include <string>

// A simple structure to hold contact data
struct Contact {
    std::string name;
    std::string phone;
};

// Function prototypes (promises to the compiler)
void addContact(std::vector<Contact>& book);
void displayContacts(const std::vector<Contact>& book);

int main() {
    std::vector<Contact> contactBook;
    int choice;

    do {
        std::cout << "\n--- CONTACT BOOK ---\n";
        std::cout << "1. Add Contact\n";
        std::cout << "2. Display All Contacts\n";
        std::cout << "3. Exit\n";
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