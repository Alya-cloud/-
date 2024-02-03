#include <iostream>
#include <vector>
#include <string>
struct Contact {
    std::string name;
    std::string phoneNumber;
};

typedef void (*ContactOperation)(std::vector<Contact>&);

void addContact(std::vector<Contact>& contacts) {
    Contact newContact;
    std::cout << "Add a name: ";
    std::cin >> newContact.name;
    std::cout << "Add a phone number: ";
    std::cin >> newContact.phoneNumber;

    contacts.push_back(newContact);
    std::cout << "Contact added" << std::endl;
}
void deleteContact(std::vector<Contact>& contacts) {
    std::string nameToDelete;
    std::cout << "Enter the name of a contact for delete: ";
    std::cin >> nameToDelete;

    auto it = std::remove_if(contacts.begin(), contacts.end(),
        [nameToDelete](const Contact& contact) {
            return contact.name == nameToDelete;
        });

    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        std::cout << "The contact has been deleted" << std::endl;
    }
    else {
        std::cout << "The contact has not been found" << std::endl;
    }
}

int main() {
    std::vector<Contact> phoneBook;            // Вектор для хранения контактов

    ContactOperation contactOperation;           // Указатель на функцию для операций с контактами

    // Меню программы
    while (true) {
        std::cout << "choose the operation:" << std::endl;
        std::cout << "1. Add the contact" << std::endl;
        std::cout << "2. Delete the contact" << std::endl;
        std::cout << "3. Exit" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            contactOperation = addContact;
            break;
        case 2:
            contactOperation = deleteContact;
            break;
        case 3:
            return 0;
        default:
            std::cout << "Wrong choice. Try again" << std::endl;
            continue;
        }

        contactOperation(phoneBook);  // Вызов функции через указатель на функцию
    }

    return 0;
}