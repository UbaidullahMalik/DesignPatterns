#include <iostream>
using namespace std;

class ProductCatalogSystem {
private:
    string catalogName;
    int numberOfProducts;

public:
    ProductCatalogSystem(string name, int numProducts) : catalogName(name), numberOfProducts(numProducts) {}

    void display() {
        cout << "This is Product Catalog System" << endl;
        cout << "Catalog Name: " << catalogName << endl;
        cout << "Number of Products: " << numberOfProducts << endl;
    }
};

class UserAuthenticationSystem {
private:
    string authenticationMethod;

public:
    UserAuthenticationSystem(string authMethod) : authenticationMethod(authMethod) {}

    void display() {
        cout << "This is User Authentication System" << endl;
        cout << "Authentication Method: " << authenticationMethod << endl;
    }
};

class OrderProcessingSystem {
private:
    bool expressShipping;

public:
    OrderProcessingSystem(bool expressShip) : expressShipping(expressShip) {}

    void display() {
        cout << "This is Order Processing System" << endl;
        cout << "Express Shipping Available: " << (expressShipping ? "Yes" : "No") << endl;
    }
};

class PaymentGatewaySystem {
private:
    string paymentMethod;

public:
    PaymentGatewaySystem(string payMethod) : paymentMethod(payMethod) {}

    void display() {
        cout << "This is Payment Gateway System" << endl;
        cout << "Payment Method: " << paymentMethod << endl;
    }
};

class ShoppingCartFacade {
private:
    ProductCatalogSystem productCatalog;
    UserAuthenticationSystem userAuth;
    OrderProcessingSystem orderProcessing;
    PaymentGatewaySystem paymentGateway;

public:
    ShoppingCartFacade(string catalogName, int numProducts, string authMethod, bool expressShip, string payMethod)
        : productCatalog(catalogName, numProducts),
          userAuth(authMethod),
          orderProcessing(expressShip),
          paymentGateway(payMethod) {}

    void displayProductCatalog() {
        productCatalog.display();
    }

    void displayUserAuthentication() {
        userAuth.display();
    }

    void displayOrderProcessing() {
        orderProcessing.display();
    }

    void displayPaymentGateway() {
        paymentGateway.display();
    }
};

int main() {
    ShoppingCartFacade facade("Hacking Products", 1000, "Ubaidullah/supersecurepassword", true, "Credit Card");

    int choice;
    while (true) {
        cout << "Menu:\n";
        cout << "1. Display Product Catalog\n";
        cout << "2. Display User Authentication\n";
        cout << "3. Display Order Processing\n";
        cout << "4. Display Payment Gateway\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                facade.displayProductCatalog();
                break;
            case 2:
                facade.displayUserAuthentication();
                break;
            case 3:
                facade.displayOrderProcessing();
                break;
            case 4:
                facade.displayPaymentGateway();
                break;
            case 5:
                cout << "Exiting\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
