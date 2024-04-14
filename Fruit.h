#include <string>

using namespace std;

class Fruit{
private:

    string name;
    string origin;
    int price;
    string expiration_date;
    int quantity;
    string producer;

public:

    Fruit();
    Fruit(const string& name,const string& origin,int price,string expiration_date,int quantity, string producer);
    Fruit(const Fruit& other);
    string get_producer();
    string get_name();
    string get_origin();
    string get_expirationdate();
    int get_quantity() const;
    float get_price();
    void set_price(float newprice);
    void set_quantity(int newquantity);
    void set_producer(string newproducer);
    void update_quantity(int added_quantity);
    bool operator==(const Fruit& other);
    bool is_near_expiration() const;
};