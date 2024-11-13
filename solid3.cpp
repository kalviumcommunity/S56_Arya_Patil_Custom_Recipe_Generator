#include <iostream>
#include <string>
#include <vector>

// Base class: Recipe
class Recipe {
public:
    virtual void addIngredients() = 0;  // Pure virtual function
    virtual void displayRecipe() = 0;   // Pure virtual function
    virtual ~Recipe() {}  // Virtual destructor
};

// Derived class: VegetarianRecipe
class VegetarianRecipe : public Recipe {
private:
    std::vector<std::string> ingredients;
public:
    void addIngredients() override {
        int numIngredients;
        std::cout << "Enter the number of ingredients for your vegetarian recipe: ";
        std::cin >> numIngredients;
        std::cin.ignore();  // To ignore any leftover newline character

        std::string ingredient;
        for (int i = 0; i < numIngredients; i++) {
            std::cout << "Enter ingredient #" << i + 1 << ": ";
            std::getline(std::cin, ingredient);
            ingredients.push_back(ingredient);
        }
    }

    void displayRecipe() override {
        std::cout << "\nVegetarian Recipe: \n";
        for (const std::string& ingredient : ingredients) {
            std::cout << "- " << ingredient << "\n";
        }
    }
};

// Derived class: NonVegetarianRecipe
class NonVegetarianRecipe : public Recipe {
private:
    std::vector<std::string> ingredients;
public:
    void addIngredients() override {
        int numIngredients;
        std::cout << "Enter the number of ingredients for your non-vegetarian recipe: ";
        std::cin >> numIngredients;
        std::cin.ignore();  // To ignore any leftover newline character

        std::string ingredient;
        for (int i = 0; i < numIngredients; i++) {
            std::cout << "Enter ingredient #" << i + 1 << ": ";
            std::getline(std::cin, ingredient);
            ingredients.push_back(ingredient);
        }
    }

    void displayRecipe() override {
        std::cout << "\nNon-Vegetarian Recipe: \n";
        for (const std::string& ingredient : ingredients) {
            std::cout << "- " << ingredient << "\n";
        }
    }
};

// Function to display any recipe
void displayRecipeDetails(Recipe* recipe) {
    recipe->addIngredients();  // Add ingredients
    recipe->displayRecipe();   // Display the recipe
}

int main() {
    // User input to select recipe type
    int choice;
    std::cout << "Choose the type of recipe: \n";
    std::cout << "1. Vegetarian\n";
    std::cout << "2. Non-Vegetarian\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    Recipe* recipe = nullptr;

    if (choice == 1) {
        recipe = new VegetarianRecipe();  // Use VegetarianRecipe
    } else if (choice == 2) {
        recipe = new NonVegetarianRecipe();  // Use NonVegetarianRecipe
    } else {
        std::cout << "Invalid choice! Exiting...\n";
        return 1;
    }

    // Display the recipe details based on user choice
    displayRecipeDetails(recipe);

    // Clean up
    delete recipe;

    return 0;
}
