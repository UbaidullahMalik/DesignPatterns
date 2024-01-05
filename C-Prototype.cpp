#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Burger {
protected:
    int id;
    string burgertype;

public:
    Burger() {}
    Burger(int id_) : id(id_) {}
    virtual ~Burger() {}
    virtual Burger* Clone() const = 0;
    virtual void Method(string burgertype_) {
        burgertype = burgertype_;
    }
};

class VegBurger : public Burger {
public:
    VegBurger() {}
    VegBurger(int id_) : Burger(id_) {
        burgertype = "Veg Burger";
    }
    Burger* Clone() const override {
        return new VegBurger(*this);
    }
};

class ChickenBurger : public Burger {
public:
    ChickenBurger() {}
    ChickenBurger(int id_) : Burger(id_) {
        burgertype = "Chicken Burger";
    }
    Burger* Clone() const override {
        return new ChickenBurger(*this);
    }
};

class ProtoTypeCache {
private:
    unordered_map<int, Burger*> burger_cache;

public:
    ProtoTypeCache() {
        burger_cache[0] = new VegBurger(0);
        burger_cache[1] = new ChickenBurger(1);
    }

    ~ProtoTypeCache() {
        for (auto& entry : burger_cache) {
            delete entry.second;
        }
    }

    Burger* CreatePrototype(int type) {
        return burger_cache[type]->Clone();
    }
};

int main() {
    ProtoTypeCache* prototype_cache = new ProtoTypeCache;

    cout << "Let's create a Burger 1 \n";
    Burger* burger1 = prototype_cache->CreatePrototype(0);
    burger1->Method("Veg Burger");
    cout << "Burger Type: " << burger1->burgertype << endl;
    delete burger1;

    cout << "\nLet's create a Burger 2 \n";
    Burger* burger2 = prototype_cache->CreatePrototype(1);
    burger2->Method("Chicken Burger");
    cout << "Burger Type: " << burger2->burgertype << endl;
    delete burger2;

    delete prototype_cache;

    return 0;
}
