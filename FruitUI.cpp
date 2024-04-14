//
// Created by alexandra on 13.04.2024.
//
#include "FruitUI.h"
#include <iostream>
using namespace std;

void FruitUI::print_menu() {
    cout << "1. Add a fruit" << endl;
    cout << "2. Delete a fruit" << endl;
    cout << "3. Display fruits by substring" << endl;
    cout << "4. Display fruits by quantity" << endl;
    cout << "5. Display fruits by expiration date" << endl;
    cout << "0. Exit" << endl;
}
void FruitUI::print_fruit(Fruit f) {
    cout << f.get_name() << " " << f.get_origin() << " " << f.get_price() << " " << f.get_expirationdate() << " " << f.get_quantity() << " " << f.get_producer() << "\n";
}
void FruitUI::run() {
   while (true) {
        print_menu();
        int option;
        cout << "Option: ";
        cin >> option;
        if (option == 1) {
            string name;
            string origin;
            int price;
            string expiration_date;
            int quantity;
            string producer;

            cout << "Name: ";
            cin >> name;
            cout << "Origin: ";
            cin >> origin;
            cout << "Price: ";
            cin >> price;
            cout << "Expiration date (yyyy-mm-dd): ";
            cin >> expiration_date;
            cout << "Quantity: ";
            cin >> quantity;
            cout << "Producer: ";
            cin >> producer;

            ctrl.add_fruit(name, origin, price, expiration_date, quantity, producer);
        }
        if (option == 2) {
            string name;
            string producer;
            cout << "Name: ";
            cin >> name;
            cout << "Producer: ";
            cin >> producer;
            ctrl.remove_fruit(name, producer);
        }
        if (option == 3) {
            string substring;
            cout << "Substring ($ to show them all): ";
            cin >> substring;
            vector<shared_ptr<Fruit>> fruitsfound = ctrl.find_by_name(substring);
            for (auto p : fruitsfound)
                print_fruit(*p);
        }
        if (option == 4) {
            int quantity;
            cout << "Quantity: ";
            cin >> quantity;
            vector<shared_ptr<Fruit>> fruitsfound = ctrl.find_by_quantity(quantity);
            for (auto p : fruitsfound)
                print_fruit(*p);
        }
        if (option == 5) {
            vector<shared_ptr<Fruit>> fruitsfound = ctrl.find_by_expiration();
            for (auto p : fruitsfound)
                print_fruit(*p);
        }
        if (option == 0)
            break;
    }
}
FruitUI::FruitUI(FruitController& _ctrl)
    : ctrl(_ctrl) {}