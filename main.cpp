#include "CatManager.h"
#include "OwnerManager.h"
#include "AdoptionManager.h"

int main() {
    // Initialize cat, owner, and adoption managers
    CatManager catManager;
    OwnerManager ownerManager;
    AdoptionManager adoptionManager(catManager, ownerManager);

    // Add cats
    catManager.addCat("Whiskers", "Persian", 3);
    catManager.addCat("Mittens", "Siamese", 2);

    // Display available cats
    catManager.displayCats();

    // Create owners
    Owner owner1 = ownerManager.createOwner("Alice");
    Owner owner2 = ownerManager.createOwner("Bob");

    // Display owners
    ownerManager.displayOwners();

    // Owners adopt cats
    adoptionManager.adoptCat(owner1, catManager.getCatByIndex(0));
    adoptionManager.adoptCat(owner2, catManager.getCatByIndex(1));

    // Display adoption details
    adoptionManager.displayAdoptions();

    // Owners give up cats for adoption
    adoptionManager.giveUpCat(owner1, catManager.getCatByIndex(0));
    adoptionManager.giveUpCat(owner2, catManager.getCatByIndex(1));

    // Display available cats after returns
    catManager.displayCats();

    return 0;
}
