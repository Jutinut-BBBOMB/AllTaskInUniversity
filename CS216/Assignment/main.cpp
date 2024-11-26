//66096502288 Jutinut Ratanamongkonkul
#include <iostream>
#include <fstream>
#include <sstream>
#include "mlist.h"

int main() {
    MessengerList list;

    std::cout << "Loading data from file \"messenger.txt\"" << std::endl;
    std::ifstream file("messenger.txt");
    std::string line;

    std::cout << "ID\tNAME\tSEX\tEXPERIENCE" << std::endl;
    std::cout << "===================================" << std::endl;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name, sex_str, expr_str;
        std::getline(iss, name, ',');
        std::getline(iss, sex_str, ',');
        std::getline(iss, expr_str);

        char sex = sex_str[0];
        int expr = std::stoi(expr_str);

        Messenger m(name, sex, expr);
        list.addMessenger(m);

        std::cout << m.getID() << "\t" << m.getName() << "\t" << m.getSex() << "\t" << m.getExperience() << std::endl;
    }

    std::cout << "===================================" << std::endl;
    std::cout << "Persons left in circle" << std::endl;
    list.printMessengerList();
    std::cout << "===================================" << std::endl;

    int count;
    std::cout << "Select number : ";
    std::cin >> count;

    Node* current = list.getHead();
    while (current->next != current) {
        for (int i = 1; i < count - 1; i++) {
            current = current->next;
        }
        Node* toRemove = current->next;
        std::cout << "Press any key ....." << std::endl;
        std::cin.get();
        std::cout << toRemove->data.getName() << " is removed" << std::endl;
        std::cout << "===================================" << std::endl;
        current->next = toRemove->next;
        delete toRemove;
        current = current->next;
        std::cout << "Persons left in circle" << std::endl;
        list.printMessengerList();
        std::cout << "===================================" << std::endl;
    }

    std::cout << "Press any key ....." << std::endl;
    std::cout << current->data.getName() << " is the bad news bearer !!";

    return 0;
}