#ifndef MLIST_H
#define MLIST_H

#include "messenger.h"

class Node {
public:
    Messenger data;
    Node* next;
    Node(const Messenger& m) : data(m), next(nullptr) {}
};

class MessengerList {
private:
    Node* head;

public:
    MessengerList();
    ~MessengerList();
    void addMessenger(const Messenger& m);
    void deleteMessenger(const std::string& name);
    void printMessengerList() const;
    Node* getHead() const { return head; }
};

#endif