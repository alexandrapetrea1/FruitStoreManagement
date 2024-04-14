#include <iostream>
#include "FruitUI.h"
#include "FruitController.h"
#include "FruitRepo.h"
int main() {

    FruitRepo repo;
    FruitController ctrl(repo);
    FruitUI ui(ctrl);
    ui.run();
    return 0;
}
