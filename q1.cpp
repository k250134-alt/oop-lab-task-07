#include <iostream>
using namespace std;
class Account {
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(int num, string name, double bal) {
        accountNumber = num;
        accountHolderName = name;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance\n";
        }
    }

    virtual void calculateInterest() {
        cout << "Interest calculation in base class\n";
    }

    virtual void printStatement() {
        cout << "Account Statement\n";
        cout << "Balance: " << balance << endl;
    }

    void getAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};
class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int num, string name, double bal, double rate, double minBal)
        : Account(num, name, bal) {
        interestRate = rate;
        minimumBalance = minBal;
    }

    void calculateInterest() {
        double interest = balance * interestRate;
        cout << "Savings Interest: " << interest << endl;
    }

    void withdraw(double amount) {
        if (balance - amount >= minimumBalance) {
            balance -= amount;
            cout << "Savings withdrawal: " << amount << endl;
        } else {
            cout << "Cannot withdraw. Minimum balance required.\n";
        }
    }

    void printStatement() {
        cout << "Savings Account Statement\n";
        cout << "Balance: " << balance << endl;
    }
};
class CheckingAccount : public Account {
public:
    CheckingAccount(int num, string name, double bal)
        : Account(num, name, bal) {}

    void calculateInterest() {
        cout << "Checking accounts usually have no interest\n";
    }

    void printStatement() {
        cout << "Checking Account Statement\n";
        cout << "Balance: " << balance << endl;
    }
};
class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    string maturityDate;

public:
    FixedDepositAccount(int num, string name, double bal, double rate, string date)
        : Account(num, name, bal) {
        fixedInterestRate = rate;
        maturityDate = date;
    }

    void calculateInterest() {
        double interest = balance * fixedInterestRate;
        cout << "Fixed Deposit Interest: " << interest << endl;
    }

    void withdraw(double amount) {
        cout << "Cannot withdraw before maturity date: " << maturityDate << endl;
    }

    void printStatement() {
        cout << "Fixed Deposit Account Statement\n";
        cout << "Balance: " << balance << endl;
        cout << "Maturity Date: " << maturityDate << endl;
    }
};

int main() {

    SavingsAccount s(101, "Ali", 5000, 0.05, 1000);
    CheckingAccount c(102, "Sara", 3000);
    FixedDepositAccount f(103, "Ahmed", 10000, 0.08, "31-12-2026");

    cout << "\nSavings Account:\n";
    s.getAccountInfo();
    s.deposit(1000);
    s.withdraw(2000);
    s.calculateInterest();
    s.printStatement();

    cout << "\nChecking Account:\n";
    c.getAccountInfo();
    c.deposit(500);
    c.withdraw(1000);
    c.calculateInterest();
    c.printStatement();

    cout << "\nFixed Deposit Account:\n";
    f.getAccountInfo();
    f.deposit(2000);
    f.withdraw(1000);
    f.calculateInterest();
    f.printStatement();

    return 0;
}
