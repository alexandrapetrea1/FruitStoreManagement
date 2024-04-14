#pragma once
#include "FruitController.h"

class FruitUI {
private:
    FruitController& ctrl;

public:
    FruitUI(FruitController& ctrl);
    void print_menu();
    void run();
    void print_fruit(Fruit f);
};


