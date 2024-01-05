#include<iostream>
#include <string>

using namespace std;

class Command {
public:
    virtual void execute() = 0;
};


class Restaurant {
public:
    void prepareMeal() 
    {
        cout << "Order Received" << endl;
        cout << "Adding Ingredients.." << endl;
        cout << "Preparing meal.." << endl;
        cout << "Meal is ready!" << endl;
    }
};
class DeliveryDriver {
public:
    void deliverOrder() {
        cout << "Preparing Order.." << endl;
        cout << "Driver Assignment" << endl;
        cout << "Order on the way.." << endl;
        cout << "Order delivered!" << endl;
    }
};

class OrderReceiver {
public:
    void updateOrderStatus() {
        cout << "Order delivered successfully!" << endl;
    }
};

class PlaceOrder : public Command {
private:
    Restaurant& restaurant;
public:
    PlaceOrder(Restaurant& restaurant_) : restaurant(restaurant_){}

    void execute() override {
        restaurant.prepareMeal();
    }
};

class DriverAssignment : public Command {
private:
    DeliveryDriver& driver;
public:
    DriverAssignment(DeliveryDriver& driver_) : driver(driver_){}

    void execute() override {
        driver.deliverOrder();
    }
};

class UpdateOrder : public Command {
private:
    OrderReceiver& orderReceiver;
public:
    UpdateOrder(OrderReceiver& orderReceiver_) : orderReceiver(orderReceiver_){}

    void execute() override {
        orderReceiver.updateOrderStatus();
    }
};

class User {
public:
    void action(Command& command) {
        command.execute();
    }
};

int main() {
    Restaurant restaurant;
    DeliveryDriver driver;
    OrderReceiver orderReceiver;
    User user;


    PlaceOrder placeOrder(restaurant);
    DriverAssignment driverAssignment(driver);
    UpdateOrder updateOrder(orderReceiver);

    user.action(placeOrder);
    user.action(driverAssignment);
    user.action(updateOrder);

    return 0;
}


