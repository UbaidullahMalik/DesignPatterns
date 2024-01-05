#include <iostream>
using namespace std;

class Plan
{
    protected:
    double rate;
    public:
        virtual double getRate() const = 0;
        virtual void calculateBill(int units) const = 0;
};

class DomesticPlan : public Plan {
public:
    DomesticPlan(double rate_)
    {
        rate = rate_;
    }
    double getRate() const override {
        return rate;
    }

    void calculateBill(int units) const override {
        cout << "Domestic Plan Bill: $" << getRate() * units << endl;
    }
};

class CommercialPlan : public Plan {
public:
    CommercialPlan(double rate_)
    {
        rate = rate_;
    }
    double getRate() const override {
        return rate;
    }

    void calculateBill(int units) const override {
        cout << "Domestic Plan Bill: $" << getRate() * units << endl;
    }
};

class InstitutionalPlan : public Plan {
public:
    InstitutionalPlan(double rate_)
    {
        rate = rate_;
    }
    double getRate() const override {
        return rate;
    }

    void calculateBill(int units) const override {
        cout << "Domestic Plan Bill: $" << getRate() * units << endl;
    }
};

class PlanFactory {
public:
    static Plan* getPlan(int planType) 
    {
        switch (planType) 
        {
            case 1:
                return new DomesticPlan(10);
            case 2:
                return new CommercialPlan(25);
            case 3:
                return new InstitutionalPlan(50);
            default:
                return nullptr;
        }
    }
};

int main() {
    int planType;
    cout << "Enter plan type:\n[1]: Domestic\n[2]: Commercial\n[3]: Institutional: ";
    cin >> planType;

    int units = 0;

    cout<<"\nEnter units: ";
    cin>> units;

    Plan* plan = PlanFactory::getPlan(planType);

    if (plan) {
        plan->calculateBill(units);
        delete plan;
    } else {
        cout << "Invalid plan type!" << endl;
    }

    return 0;
}
