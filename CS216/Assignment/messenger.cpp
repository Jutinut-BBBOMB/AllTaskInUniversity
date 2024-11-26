#include "messenger.h"

int Messenger::nextID = 1;

Messenger::Messenger(const std::string& name, char sex, int expr)
    : name(name), sex(sex), expr(expr) {
    id = nextID++;
}

std::string Messenger::getName() const {
    return name;
}

int Messenger::getID() const {
    return id;
}

char Messenger::getSex() const {
    return sex;
}

int Messenger::getExperience() const {
    return expr;
}