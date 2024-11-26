#ifndef MESSENGER_H
#define MESSENGER_H

#include <string>

class Messenger {
private:
    static int nextID;
    int id;
    std::string name;
    char sex;
    int expr;

public:
    Messenger(const std::string& name, char sex, int expr);
    std::string getName() const;
    int getID() const;
    char getSex() const;
    int getExperience() const;
};

#endif