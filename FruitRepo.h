#pragma once
#include <vector>
#include<memory>
#include "Fruit.h"


using namespace std;

class FruitRepo {
private:
    vector<shared_ptr<Fruit>> fruits;

public:
    //FruitRepo();  // Constructor to initialize filename
    void add(const Fruit& fruit);
    void delete_fruit(const string& name, const string& producer);
    vector<Fruit> get_all() const;
    vector<shared_ptr<Fruit>> find_by_name(const string substring) const;
    vector<shared_ptr<Fruit>> get_expiring_products(int max_quantity);
    vector<shared_ptr<Fruit>> find_by_quantity(const int quantity) const;
    vector<shared_ptr<Fruit>> find_by_expiration() const;
};


