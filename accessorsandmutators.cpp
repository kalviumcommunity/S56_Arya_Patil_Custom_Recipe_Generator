#include <iostream>
#include <string>
#include <vector>

// Ingredient Class
class Ingredient {
private:
    std::string name;
    double quantity;
    std::string unit;

public:
    // Constructor
    Ingredient(const std::string& name = "", double quantity = 0, const std::string& unit = "")
        : name(name), quantity(quantity), unit(unit) {}

    // Accessors (getters)
    std::string getName() const { return name; }
    double getQuantity() const { return quantity; }
    std::string getUnit() const { return unit; }

    // Mutators (setters)
    void setName(const std::string& name) { this->name = name; }
    void setQuantity(double quantity) { this->quantity = quantity; }
    void setUnit(const std::string& unit) { this->unit = unit; }

    // Display method
    void display() const {
        std::cout << quantity << " " << unit << " of " << name << std::endl;
    }
};

// Recipe Class
class Recipe {
private:
    std::string name;
    std::vector<Ingredient> ingredients;

public:
    // Constructor
    Recipe(const std::string& name) : name(name) {}

    // Accessors (getters)
    std::string getName() const { return name; }
    const std::vector<Ingredient>& getIngredients() const { return ingredients; }

    // Mutators (setters)
    void setName(const std::string& name) { this->name = name; }

    // Add ingredient to the recipe
    void addIngredient(const Ingredient& ingredient) {
        ingredients.push_back(ingredient);
    }

    // Display recipe
    void display() const {
        std::cout << "Recipe: " << name << std::endl;
        std::cout << "Ingredients:" << std::endl;
        for (const auto& ingredient : ingredients) {
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

        std::cout << "Enter ingredient #" << (i + 1) << " unit: ";
        std::getline(std::cin, unit);

        // Create Ingredient object and add to recipe
        Ingredient ingredient(name, quantity, unit);
        recipe.addIngredient(ingredient);
    }

    // Display the recipe
    recipe.display();

    return 0;
}
