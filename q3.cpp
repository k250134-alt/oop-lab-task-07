#include <iostream>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode, currencySymbol;
    double exchangeRate;

public:
    Currency(double a, string code, string sym, double rate) {
        amount = a;
        currencyCode = code;
        currencySymbol = sym;
        exchangeRate = rate;
    }

    virtual double convertToBase() {
        return amount * exchangeRate;
    }

    double convertTo(double targetRate) {
        double base = convertToBase();
        return base / targetRate;
    }

    virtual void displayCurrency() {
        cout << currencySymbol << amount << " (" << currencyCode << ")\n";
    }
};

class Dollar : public Currency {
public:
    Dollar(double a) : Currency(a, "USD", "$", 1.0) {}

    double convertToBase() {
        return amount * exchangeRate;
    }

    void displayCurrency() {
        cout << "$" << amount << " USD\n";
    }
};

class Euro : public Currency {
public:
    Euro(double a) : Currency(a, "EUR", "€", 1.1) {}

    double convertToBase() {
        return amount * exchangeRate;
    }

    void displayCurrency() {
        cout << "€" << amount << " EUR\n";
    }
};

class Rupee : public Currency {
public:
    Rupee(double a) : Currency(a, "PKR", "Rs", 0.0035) {}

    double convertToBase() {
        return amount * exchangeRate;
    }

    void displayCurrency() {
        cout << "Rs " << amount << " PKR\n";
    }
};

int main() {
    Dollar d(100);
    Euro e(100);
    Rupee r(10000);

    d.displayCurrency();
    cout << "In Base: " << d.convertToBase() << endl;

    e.displayCurrency();
    cout << "In Base: " << e.convertToBase() << endl;

    r.displayCurrency();
    cout << "In Base: " << r.convertToBase() << endl;

    return 0;
}
