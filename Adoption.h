// Adoption.h
#ifndef ADOPTION_H
#define ADOPTION_H

#include "Owner.h"
#include "Cat.h"

class Adoption {
public:
    Adoption(const Owner& owner, const Cat& cat);

    const Owner& getOwner() const;
    const Cat& getCat() const;

private:
    const Owner& owner;
    const Cat& cat;
};

#endif // ADOPTION_H

// Adoption.cpp
#include "Adoption.h"

Adoption::Adoption(const Owner& owner, const Cat& cat) : owner(owner), cat(cat) {}

const Owner& Adoption::getOwner() const {
    return owner;
}

const Cat& Adoption::getCat() const {
    return cat;
}
