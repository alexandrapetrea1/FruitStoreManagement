
#include "Fruit.h"
#include<chrono>
#include<iomanip>

Fruit::Fruit(){

}

Fruit::Fruit(const string &_name, const string &_origin, int _price, string _expiration_date, int _quantity, string _producer) {
    name = _name;
    origin = _origin;
    price = _price;
    expiration_date = _expiration_date;
    quantity = _quantity;
    producer = _producer;
}

Fruit::Fruit(const Fruit &other) {
    name = other.name;
    origin = other.origin;
    price = other.price;
    expiration_date = other.expiration_date;
    quantity = other.quantity;
    producer = other.producer;
}

string Fruit::get_name() {
    return name;
}

string Fruit::get_expirationdate() {
    return expiration_date;
}

string Fruit::get_origin()  {
    return origin;
}

float Fruit::get_price() {
    return price;
}

void Fruit::set_price(float newprice) {
    newprice = price;
}

void Fruit::set_quantity(int newquantity)  {
    newquantity = quantity;
}

void Fruit::update_quantity(int added_quantity) {
    quantity = quantity + added_quantity;
}

bool Fruit::operator==(const Fruit &other) {
    return name == other.name && origin == other.origin;
}

int Fruit::get_quantity () const  {
    return quantity;
}


string Fruit::get_producer() {
    return producer;
}

void Fruit::set_producer(string newproducer) {

    producer = newproducer;
}




