/*Create a base class Account with:

Overload the + operator to add balances of two accounts.
Use a virtual function displayBalance() to display the account balance.
Create derived classes SavingsAccount and CurrentAccount that:

Override the displayBalance() function.
Demonstrate the use of the + operator and the overridden function.
*/

#include <iostream>
#include <string>
using namespace std;

class Account
{
protected:
    int balance;

public:
    Account(int b = 0) : balance(b) {}

    // Overload + operator to add balances of two accounts
    Account operator+(const Account &other) const
    {
        return Account(balance + other.balance);
    }

    virtual void displayBalance() const
    {
        cout << "Total Balance: " << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account
{
public:
    SavingsAccount(int b) : Account(b) {}

    void displayBalance() const override
    {
        cout << "Savings Account Balance: " << balance << endl;
    }
};

class CurrentAccount : public Account
{
public:
    CurrentAccount(int b) : Account(b) {}

    void displayBalance() const override
    {
        cout << "Current Account Balance: " << balance << endl;
    }
};

int main()
{
    // Create savings and current accounts
    SavingsAccount savings(1000);
    CurrentAccount current(5000);

    // Add balances using overloaded + operator
    Account total = savings + current;

    // Demonstrate runtime polymorphism
    Account *accounts[2] = {&savings, &current};

    cout << "Individual Account Balances:" << endl;
    for (int i = 0; i < 2; i++)
    {
        accounts[i]->displayBalance();
    }

    cout << "\nTotal Account Balance:" << endl;
    total.displayBalance();

    return 0;
}
