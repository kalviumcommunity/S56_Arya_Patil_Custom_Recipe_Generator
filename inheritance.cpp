#include <iostream>
using namespace std;

// Base class: Product
class Product {
public:
    int productID;
    string productName;
    double price;

    // Function to take product input
    void inputProductDetails() {
        cout << "Enter Product ID: ";
        cin >> productID;
        cout << "Enter Product Name: ";
        cin.ignore(); // To avoid getline() issue after cin
        getline(cin, productName);
        cout << "Enter Product Price: ";
        cin >> price;
    }

    // Function to display product details
    void displayProduct() const {
        cout << "\nProduct ID: " << productID << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Price: $" << price << endl;
    }
};

// Derived class using **Single Inheritance**: Electronics
class Electronics : public Product {
public:
    int warranty;  // warranty period in months

    // Function to take input for electronics-specific details
    void inputElectronicsDetails() {
        inputProductDetails(); // Take product input first
        cout << "Enter Warranty (in months): ";
        cin >> warranty;
    }

    // Function to display electronics details
    void displayElectronics() const {
        displayProduct();
        cout << "Warranty: " << warranty << " months" << endl;
    }
};

// Derived class using **Multilevel Inheritance**: Laptop
class Laptop : public Electronics {
public:
    double weight;  // Weight of the laptop in kilograms

    // Function to take input for laptop-specific details
    void inputLaptopDetails() {
        inputElectronicsDetails(); // Take electronics input first
        cout << "Enter Weight (in kg): ";
        cin >> weight;
    }

    // Function to display laptop details
    void displayLaptop() const {
        displayElectronics();
        cout << "Weight: " << weight << " kg" << endl;
    }
};

int main() {
    Laptop laptop; // Create an instance of Laptop

    // Take input from the user
    cout << "Enter Laptop Details:\n";
    laptop.inputLaptopDetails();

    // Display the entered details
    cout << "\n--- Laptop Details ---\n";
    laptop.displayLaptop();

    return 0;
}
