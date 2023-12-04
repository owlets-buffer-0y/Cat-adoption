// AdoptionManager.h
#ifndef ADOPTION_MANAGER_H
#define ADOPTION_MANAGER_H

#include "Adoption.h"
#include "CatManager.h"
#include "OwnerManager.h"
#include <vector>

class AdoptionManager {
public:
    AdoptionManager(CatManager& catManager, OwnerManager& ownerManager);
    void adoptCat(const Owner& owner, const Cat& cat);
    void giveUpCat(const Owner& owner, const Cat& cat);
    void displayAdoptions() const;

private:
    CatManager& catManager;
    OwnerManager& ownerManager;
    std::vector<Adoption> adoptions;
};

#endif // ADOPTION_MANAGER_H

// AdoptionManager.cpp
#include "AdoptionManager.h"
#include <iostream>

AdoptionManager::AdoptionManager(CatManager& catManager, OwnerManager& ownerManager)
    : catManager(catManager), ownerManager(ownerManager) {}

void AdoptionManager::adoptCat(const Owner& owner, const Cat& cat) {
    Adoption adoption(owner, cat);
    catManager.adoptCat(catManager.getCatIndex(cat));
    adoptions.push_back(adoption);
}

void AdoptionManager::giveUpCat(const Owner& owner, const Cat& cat) {
    catManager.giveUpCat(catManager.getCatIndex(cat));
    for (size_t i = 0; i < adoptions.size(); ++i) {
        if (&adoptions[i].getOwner() == &owner && &adoptions[i].getCat() == &cat) {
            adoptions.erase(adoptions.begin() + i);
            break;
        }
    }
}

void AdoptionManager::displayAdoptions() const {
    std::cout << "Adoption Details:\n";
    for (const Adoption& adoption : adoptions) {
        std::cout << "Owner: " << adoption.getOwner().getName() << ", Cat: " << adoption.getCat().getName() << "\n";
    }
    std::cout << "\n";
}
