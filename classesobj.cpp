#include <iostream>
#include <string>
#include <vector>

// Ingredient Class
class Ingredient {
public:
    std::string name;
    double quantity;
    std::string unit;

    // Constructor
    Ingredient(std::string n, double q, std::string u) : name(n), quantity(q), unit(u) {}

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

    // Constructor
    Recipe(std::string n) : name(n) {}

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
    // Creating Ingredient objects
    Ingredient sugar("Sugar", 100, "grams");
    Ingredient flour("Flour", 200, "grams");

    // Creating Recipe object
    Recipe cake("Cake");

    // Adding ingredients to the recipe
    cake.addIngredient(sugar);
    cake.addIngredient(flour);

    // Display the recipe
    cake.display();

    return 0;
}
