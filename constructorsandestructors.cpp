#include <iostream>
using namespace std;

class FoodItem {
    string name;
    int calories;

public:
    // Default Constructor
    FoodItem() {
        name = "Unknown";
        calories = 0;
        cout << "Default Constructor Called\n";
    }

    // Parameterized Constructor
    FoodItem(string n, int cal) {
        name = n;
        calories = cal;
        cout << "Parameterized Constructor Called\n";
    }

    // Destructor
    ~FoodItem() {
        cout << "Destructor Called for: " << name << endl;
    }

    void display() {
        cout << "Food: " << name << ", Calories: " << calories << endl;
    }
};

int main() {
    // Variables for user input
    string foodName;
    int foodCalories;

    // User Input for the first food item
    cout << "Enter the name of the first food item: ";
    getline(cin, foodName); // To get the full name including spaces

    cout << "Enter the number of calories for the first food item: ";
    cin >> foodCalories;

    // Creating the object with user input (Parameterized Constructor)
    FoodItem item1(foodName, foodCalories);
    item1.display();

    // Clear the input buffer to prevent issues with the second getline
    cin.ignore(1, '\n');  // Ignore the leftover newline

    // User Input for the second food item
    cout << "\nEnter the name of the second food item: ";
    getline(cin, foodName);

    cout << "Enter the number of calories for the second food item: ";
    cin >> foodCalories;

    // Creating another object with user input (Parameterized Constructor)
    FoodItem item2(foodName, foodCalories);
    item2.display();

    return 0;
}
