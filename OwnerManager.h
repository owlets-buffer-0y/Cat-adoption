// OwnerManager.h
#ifndef OWNER_MANAGER_H
#define OWNER_MANAGER_H

#include "Owner.h"
#include <vector>

class OwnerManager {
public:
    const Owner& createOwner(const std::string& name);
    void displayOwners() const;

private:
    std::vector<Owner> owners;
};

#endif // OWNER_MANAGER_H

// OwnerManager.cpp
#include "OwnerManager.h"
#include <iostream>

const Owner& OwnerManager::createOwner(const std::string& name) {
    owners.emplace_back(name);
    return owners.back();
}

void OwnerManager::displayOwners() const {
    std::cout << "Owners:\n";
    for (size_t i = 0; i < owners.size(); ++i) {
        const Owner& owner = owners[i];
        std::cout << i + 1 << ". " << owner.getName() << "\n";
    }
    std::cout << "\n";
}
