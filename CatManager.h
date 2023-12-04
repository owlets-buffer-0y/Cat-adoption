// CatManager.h
#ifndef CAT_MANAGER_H
#define CAT_MANAGER_H

#include "Cat.h"
#include <vector>

class CatManager {
public:
    void addCat(const std::string& name, const std::string& breed, int age);
    void displayCats() const;
    const Cat& getCatByIndex(int index) const;
    void adoptCat(int index);
    void giveUpCat(int index);

private:
    std::vector<Cat> cats;
};

#endif // CAT_MANAGER_H

// CatManager.cpp
#include "CatManager.h"
#include <iostream>

void CatManager::addCat(const std::string& name, const std::string& breed, int age) {
    Cat cat(name, breed, age);
    cats.push_back(cat);
}

void CatManager::displayCats() const {
    std::cout << "Available Cats:\n";
    for (size_t i = 0; i < cats.size(); ++i) {
        const Cat& cat = cats[i];
        std::string availability = cat.isAvailable() ? "Available" : "Adopted";
        std::cout << i + 1 << ". " << cat.getName() << " - " << cat.getBreed() << " - "
                  << cat.getAge() << " years old - " << availability << "\n";
    }
    std::cout << "\n";
}

const Cat& CatManager::getCatByIndex(int index) const {
    return cats[index];
}

void CatManager::adoptCat(int index) {
    Cat& cat = cats[index];
    if (cat.isAvailable()) {
        cat.setAvailable(false);
    } else {
        std::cout << "Cat not available for adoption.\n";
    }
}

void CatManager::giveUpCat(int index) {
    cats[index].setAvailable(true);
}
