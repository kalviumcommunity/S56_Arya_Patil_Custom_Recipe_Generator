#include <iostream>
#include <string>

// Ingredient Class
class Ingredient {
public:
    std::string name;
    double quantity;
    std::string unit;

    // Constructor
    Ingredient(std::string name = "", double quantity = 0, std::string unit = "") {
        this->name = name;
        this->quantity = quantity;
        this->unit = unit;
    }

    // Method to set ingredient details
    void setDetails(std::string name, double quantity, std::string unit) {
        this->name = name;
        this->quantity = quantity;
        this->unit = unit;
    }

    // Display method
    void display() const {
        std::cout << quantity << " " << unit << " of " << name << std::endl;
    }
};

// Recipe Class
class Recipe {
public:
    std::string name;
    int numIngredients;
    Ingredient* ingredients;  // Array of Ingredient objects

    // Constructor
    Recipe(std::string name, int numIngredients) {
        this->name = name;
        this->numIngredients = numIngredients;
        ingredients = new Ingredient[numIngredients];  // Allocate memory for array
    }

    // Destructor
    ~Recipe() {
        delete[] ingredients;  // Free allocated memory
    }

    // Method to add ingredients to the array
    void addIngredient(int index, std::string name, double quantity, std::string unit) {
        if (index >= 0 && index < numIngredients) {
            ingredients[index].setDetails(name, quantity, unit);
        }
    }

    // Display the recipe
    void display() const {
        std::cout << "Recipe: " << name << std::endl;
        std::cout << "Ingredients:" << std::endl;
        for (int i = 0; i < numIngredients; ++i) {
            ingredients[i].display();
        }
    }
};

// Main Function
int main() {
    std::string recipeName;
    int numIngredients;

    // Get the recipe name from the user
    std::cout << "Enter the recipe name: ";
    std::getline(std::cin, recipeName);

    // Get the number of ingredients from the user
    std::cout << "Enter the number of ingredients: ";
    std::cin >> numIngredients;
    std::cin.ignore();  // Ignore the newline character left in the buffer

    // Create Recipe object with an array of Ingredient objects
    Recipe recipe(recipeName, numIngredients);

    // Get ingredients details from the user
    for (int i = 0; i < numIngredients; ++i) {
        std::string name;
        double quantity;
        std::string unit;

        std::cout << "Enter ingredient #" << (i + 1) << " name: ";
        std::cin.ignore();  // Ignore the newline character left in the buffer
        std::getline(std::cin, name);

        std::cout << "Enter ingredient #" << (i + 1) << " quantity: ";
        std::cin >> quantity;
        std::cin.ignore();  // Ignore the newline character left in the buffer

        std::cout << "Enter ingredient #" << (i + 1) << " unit: ";
        std::getline(std::cin, unit);

        // Add ingredient to the array in the Recipe object
        recipe.addIngredient(i, name, quantity, unit);
    }

    // Display the recipe
    recipe.display();

    return 0;
}
