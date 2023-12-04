// Owner.h
#ifndef OWNER_H
#define OWNER_H

#include <string>

class Owner {
public:
    Owner(const std::string& name);

    const std::string& getName() const;

private:
    std::string name;
};

#endif // OWNER_H

// Owner.cpp
#include "Owner.h"

Owner::Owner(const std::string& name) : name(name) {}

const std::string& Owner::getName() const {
    return name;
}
