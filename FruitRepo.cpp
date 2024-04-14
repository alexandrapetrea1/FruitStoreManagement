
#include "FruitRepo.h"
#include <algorithm>
#include<memory>
#include <vector>
#include <string>

void FruitRepo::add(const Fruit &fruit) {
   auto it = find_if(fruits.begin(), fruits.end(),
   [&fruit](shared_ptr<Fruit>& existingFruit) {
       return *existingFruit == fruit;
   });
    //fructul deja exista
   if(it != fruits.end()) {
       (*it)->update_quantity(fruit.get_quantity());
   }
   else
       fruits.push_back(make_shared<Fruit>(fruit));
}


void FruitRepo::delete_fruit(const string &name, const string &producer) {

    fruits.erase(remove_if(fruits.begin(),fruits.end(),
                           [&name, &producer](const shared_ptr<Fruit>& existingFruit) {
                               return existingFruit->get_name() == name && existingFruit->get_producer() == producer;
                           }),fruits.end());
    }



vector<shared_ptr<Fruit>> FruitRepo::find_by_name(const string substring) const {
    vector<shared_ptr<Fruit>> filteredFruits;

    if (substring != "$") {
        // Filtrăm fructele în funcție de substring
        std::copy_if(fruits.begin(), fruits.end(), back_inserter(filteredFruits),
                     [&substring](const shared_ptr<Fruit> &fruit) {
                         return fruit->get_name().find(substring) != std::string::npos;
                     });
    }
    else {
        filteredFruits = fruits;
    }

    // Sortăm fructele filtrate după nume
    std::sort(filteredFruits.begin(), filteredFruits.end(),
              [](const std::shared_ptr<Fruit>& a, const std::shared_ptr<Fruit>& b) {
                  return a->get_name() < b->get_name();
              });

    return filteredFruits;
}

vector<shared_ptr<Fruit>> FruitRepo::find_by_quantity(const int quantity) const {
    vector<shared_ptr<Fruit>> filteredFruits;
    std::copy_if(fruits.begin(), fruits.end(), back_inserter(filteredFruits),
                 [&quantity](const shared_ptr<Fruit> &fruit) {
                     return fruit->get_quantity() < quantity;
                 });
    std::sort(filteredFruits.begin(), filteredFruits.end(),
              [](const std::shared_ptr<Fruit>& a, const std::shared_ptr<Fruit>& b) {
                  return a->get_quantity() < b->get_quantity();
              });
    return filteredFruits;
}
vector<shared_ptr<Fruit>> FruitRepo::find_by_expiration() const {
    vector<shared_ptr<Fruit>> filteredFruits = fruits;
    std::sort(filteredFruits.begin(), filteredFruits.end(),
              [](const std::shared_ptr<Fruit>& a, const std::shared_ptr<Fruit>& b) {
                  return a->get_expirationdate() < b->get_expirationdate();
              });
    return filteredFruits;
}



