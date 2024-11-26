#include "mlist.h"
#include <iostream>

MessengerList::MessengerList() : head(nullptr) {}

MessengerList::~MessengerList() {
    if (!head) return;
    Node* current = head->next;
    while (current != head) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    delete head;
}

void MessengerList::addMessenger(const Messenger& m) {
    Node* newNode = new Node(m);
    if (!head) {
        head = newNode;
        head->next = head;
    }
    else {
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = head;
    }
}

void MessengerList::deleteMessenger(const std::string& name) {
    if (!head) return;

    Node* current = head;
    Node* prev = nullptr;

    do {
        if (current->data.getName() == name) {
            if (current == head) {
                if (head->next == head) {
                    delete head;
                    head = nullptr;
                }
                else {
                    Node* last = head;
                    while (last->next != head) last = last->next;
                    head = head->next;
                    last->next = head;
                    delete current;
                }
            }
            else {
                prev->next = current->next;
                delete current;
            }
            return;
        }
        prev = current;
        current = current->next;
    } while (current != head);
}

void MessengerList::printMessengerList() const {
    if (!head) return;
    Node* current = head;
    do {
        std::cout << current->data.getName() << " ";
        current = current->next;
    } while (current != head);
    std::cout << std::endl;
}