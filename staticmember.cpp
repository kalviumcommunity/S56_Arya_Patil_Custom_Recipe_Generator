#include <iostream>
using namespace std;
//Static Member Function (getTotalAccounts): This function is declared with the static keyword, 
//meaning it can be called without creating an instance of the class.
// It accesses the static variable totalAccounts, which tracks the number of Account objects created.

//static Variable (totalAccounts): This variable is shared across all instances of the Account class.
// It's initialized to 0 and is incremented every time a new Account object is created.


class Account {
private:
    static int totalAccounts; // Static variable to keep track of the total number of accounts
    int accountNumber;
    double balance;

public:
    // Constructor to initialize an account with user input
    Account(int accNum, double bal) : accountNumber(accNum), balance(bal) {
        totalAccounts++; // Increment totalAccounts when a new account is created
    }

    // Static member function to return the total number of accounts
    static int getTotalAccounts() {
        return totalAccounts;
    }

    // Member function to display account details
    void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

// Initialize the static variable outside the class definition
int Account::totalAccounts = 0;

int main() {
    int numAccounts;

    // Ask the user how many accounts they want to create
    cout << "Enter the number of accounts you want to create: ";
    cin >> numAccounts;

    Account* accounts[numAccounts]; // Array of Account pointers

    // Loop to create accounts based on user input
    for (int i = 0; i < numAccounts; i++) {
        int accNum;
        double bal;

        cout << "\nEnter details for account " << i + 1 << ":\n";
        cout << "Account Number: ";
        cin >> accNum;
        cout << "Balance: ";
        cin >> bal;

        // Create a new account and store it in the array
        accounts[i] = new Account(accNum, bal);
    }

    // Display all account details
    cout << "\nAccount Details:\n";
    for (int i = 0; i < numAccounts; i++) {
        accounts[i]->displayAccountInfo();
        cout << endl;
    }

    // Display total number of accounts using static member function
    cout << "Total Accounts: " << Account::getTotalAccounts() << endl;

    // Clean up memory
    for (int i = 0; i < numAccounts; i++) {
        delete accounts[i];
    }

    return 0;
}
