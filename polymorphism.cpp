#include <iostream>
#include <string>
using namespace std;

// Product class demonstrating **Constructor Overloading**
class Product {
public:
    string name;
    double price;

    // Default constructor
    Product() {
        name = "Unknown Product";
        price = 0.0;
    }

    // Parameterized constructor
    Product(string prodName, double prodPrice) {
        name = prodName;
        price = prodPrice;
    }

    // Display function
    void displayProduct() const {
        cout << "Product: " << name << ", Price: $" << price << endl;
    }
};

// Calculation class demonstrating **Function Overloading**
class Calculator {
public:
    // Function to calculate the total price for one product
    double calculateTotal(double price) {
        return price;
    }

    // Overloaded function to calculate the total price for multiple products
    double calculateTotal(double price, int quantity) {
        return price * quantity;
    }
};

int main() {
    // Demonstrate Constructor Overloading with user input
    cout << "Enter Product Name: ";
    string name;
    getline(cin, name);

    cout << "Enter Product Price: ";
    double price;
    cin >> price;

    // Create product using parameterized constructor
    Product p1(name, price);
    cout << "\nProduct created using parameterized constructor:\n";
    p1.displayProduct();

    // Create product using default constructor
    Product p2;
    cout << "\nProduct created using default constructor:\n";
    p2.displayProduct();

    // Demonstrate Function Overloading with user input
    Calculator calc;
    cout << "\nEnter quantity for the product: ";
    int quantity;
    cin >> quantity;

    double total = calc.calculateTotal(price, quantity);
    cout << "\nTotal price for " << quantity << " units: $" << total << endl;

    return 0;
}
