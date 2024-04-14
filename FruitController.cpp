
#include "FruitController.h"

FruitController::FruitController(FruitRepo& _repo) : repo(_repo) {
    add10fruits();
}

void FruitController::add_fruit(const string& name, const string& origin, int price, string expiration_date, int quantity, string producer) {
    Fruit newfruit(name, origin, price, expiration_date, quantity, producer);
    repo.add(newfruit);
}
void FruitController::remove_fruit(const string& name, const string& producer) {
    repo.delete_fruit(name, producer);
}
vector<shared_ptr<Fruit>> FruitController::find_by_name(const string substring) const {
    return repo.find_by_name(substring);
}
vector<shared_ptr<Fruit>> FruitController::find_by_quantity(const int quantity) const {
    return repo.find_by_quantity(quantity);
}
vector<shared_ptr<Fruit>> FruitController::find_by_expiration() const {
    return repo.find_by_expiration();
}

void FruitController::add10fruits() {
    add_fruit("banana", "romania", 15, "2024-05-02", 20, "Catalin");
    add_fruit("capsuni", "spania", 28, "2024-07-18", 400, "Laurentiu");
    add_fruit("mere", "romania", 2, "2024-05-23", 1200, "Alma");
    add_fruit("pere", "Peru", 6, "2024-09-02", 130, "Ionela");
    add_fruit("kiwi", "Bali", 9, "2024-12-02", 56, "Livia");
    add_fruit("lebenita", "dabuleni", 56, "2024-07-07", 20, "Marinela");
    add_fruit("zmeura", "romania", 34, "2024-08-02", 33, "Alin");
    add_fruit("portocale", "ecuador", 17, "2024-12-12", 80, "Cosmin");
    add_fruit("cirese", "romania", 45, "2024-04-23", 10000, "Alexandra");
    add_fruit("piersici", "guatemala", 14, "2024-11-02", 20, "Andrei");
}