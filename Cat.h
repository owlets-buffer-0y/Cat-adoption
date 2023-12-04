// Cat.h
#ifndef CAT_H
#define CAT_H

#include <string>

class Cat {
public:
    Cat(const std::string& name, const std::string& breed, int age);

    const std::string& getName() const;
    const std::string& getBreed() const;
    int getAge() const;
    bool isAvailable() const;
    void setAvailable(bool available);

private:
    std::string name;
    std::string breed;
    int age;
    bool available;
};

#endif // CAT_H

// Cat.cpp
#include "Cat.h"

Cat::Cat(const std::string& name, const std::string& breed, int age)
    : name(name), breed(breed), age(age), available(true) {}

const std::string& Cat::getName() const {
    return name;
}

const std::string& Cat::getBreed() const {
    return breed;
}

int Cat::getAge() const {
    return age;
}

bool Cat::isAvailable() const {
    return available;
}

void Cat::setAvailable(bool available) {
    this->available = available;
}
