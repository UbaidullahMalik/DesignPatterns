#include <iostream>
using namespace std;

//Name: Ubaid Ullah
//Roll no: 20i0541
//Question # 03

class Card {
protected:
    float creditLimit;
public:
    Card() {} ;
    Card(float creditLimit_) : creditLimit(creditLimit_) {};
    virtual void getCreditLimit() = 0;
};

class SilverCard : public Card {
public:
    SilverCard(float creditLimit_) {
        creditLimit = creditLimit_;
    };
    void getCreditLimit() override{
        cout << "Your Card is Silver Card and your Credit Limit is: " << creditLimit << " PKR" << endl;
    }
};

class GoldCard : public Card {
public:
    GoldCard(float creditLimit_) {
        creditLimit = creditLimit_;
    };
    void getCreditLimit() override {
        cout << "Your Card is Gold Card and your Credit Limit is: " << creditLimit << " PKR" << endl;
    }
};

class PlatinumCard : public Card {
public:
    PlatinumCard(float creditLimit_) {
        creditLimit = creditLimit_;
    };
    void getCreditLimit() override {
        cout << "Your Card is Platinum Card and your Credit Limit is: " << creditLimit << " PKR" << endl;
    }
};

class Bank {
public:
    Card* getCreditCard(int monthlySalary)
    {
        if (monthlySalary >= 100000)
        {
            return new PlatinumCard(500000);
        }
        else if (monthlySalary < 100000 && monthlySalary > 50000)
        {
            return new GoldCard(250000);
        }
        else
        {
            return new SilverCard(100000);
        }
    }
};

int main()
{
    Bank b;
    static Card* issuedCard;
    int monthlySalary = 0;
    cout << "Please enter your monthly salary" << endl;
    cin >> monthlySalary;

    issuedCard = b.getCreditCard(monthlySalary);
    issuedCard->getCreditLimit();
}

