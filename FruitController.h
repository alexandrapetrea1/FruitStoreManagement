
#pragma once
#include "FruitRepo.h"

using namespace std;

class FruitController {
private:
    FruitRepo& repo;

public:
    FruitController(FruitRepo& _repo);

    void add_fruit(const string& name, const string& origin, int price, string expiration_date, int quantity, string producer);
    void remove_fruit(const string& name, const string& producer);
    vector<shared_ptr<Fruit>> find_by_name(const string substring) const;
    vector<shared_ptr<Fruit>> find_by_quantity(const int quantity) const;
    vector<shared_ptr<Fruit>> find_by_expiration() const;
    void add10fruits();
};


