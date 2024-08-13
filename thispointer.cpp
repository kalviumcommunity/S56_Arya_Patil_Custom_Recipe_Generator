#include <iostream>
#include <string>
#include <vector>

// Ingredient Class
class Ingredient {
public:
    std::string name;
    double quantity;
    std::string unit;

    // Constructor using the this pointer
    Ingredient(std::string name, double quantity, std::string unit) {
        this->name = name;
        this->quantity = quantity;
        this->unit = unit;
    }

    // Method to set the ingredient details using the this pointer
    Ingredient& setDetails(std::string name, double quantity, std::string unit) {
        this->name = name;
        this->quantity = quantity;
        this->unit = unit;
        return *this;  // Returning the current object
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
    std::vector<Ingredient> ingredients;

    // Constructor using the this pointer
    Recipe(std::string name) {
        this->name = name;
    }

    // Add ingredient to the recipe
    void addIngredient(const Ingredient &ingredient) {
        ingredients.push_back(ingredient);
    }

    // Display recipe
    void display() const {
        std::cout << "Recipe: " << name << std::endl;
        std::cout << "Ingredients:" << std::endl;
        for (const auto &ingredient : ingredients) {
            ingredient.display();
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

    // Create Recipe object
    Recipe recipe(recipeName);

    // Get the number of ingredients from the user
    std::cout << "Enter the number of ingredients: ";
    std::cin >> numIngredients;
    std::cin.ignore();  // Ignore the newline character left in the buffer

    // Get ingredients details from the user
    for (int i = 0; i < numIngredients; ++i) {
        std::string name;
        double quantity;
        std::string unit;

        std::cout << "Enter ingredient #" << (i + 1) << " name: ";
        std::getline(std::cin, name);

        std::cout << "Enter ingredient #" << (i + 1) << " quantity: ";
        std::cin >> quantity;
        std::cin.ignore();  // Ignore the newline character left in the buffer

        std::cout << "Enter ingredient #" << (i + 1) <<" unit: ";
        std::getline(std::cin, unit);

        // Create Ingredient object and add to recipe
        Ingredient ingredient(name, quantity, unit);
        recipe.addIngredient(ingredient);
    }

    // Display the recipe
    recipe.display();

    return 0;
}
