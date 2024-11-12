#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Abstract base class representing a generic Recipe
class Recipe {
protected:
    string name;
    vector<string> ingredients;
    vector<string> steps;

public:
    Recipe(string n) : name(n) {}

    // Pure virtual function making Recipe an abstract class
    virtual void displayRecipe() = 0; // Must be implemented by derived classes

    virtual ~Recipe() {} // Virtual destructor for safe cleanup
};

// Derived class for Vegetarian recipes
class VegetarianRecipe : public Recipe {
public:
    VegetarianRecipe(string n, vector<string> ingr, vector<string> stps) 
        : Recipe(n) {
        ingredients = ingr;
        steps = stps;
    }

    // Override the displayRecipe() function for Vegetarian recipes
    void displayRecipe() override {
        cout << "\nVegetarian Recipe: " << name << endl;
        cout << "Ingredients:" << endl;
        for (const auto& ingredient : ingredients) {
            cout << "- " << ingredient << endl;
        }
        cout << "Steps:" << endl;
        for (const auto& step : steps) {
            cout << "- " << step << endl;
        }
    }
};

// Derived class for Non-Vegetarian recipes
class NonVegetarianRecipe : public Recipe {
public:
    NonVegetarianRecipe(string n, vector<string> ingr, vector<string> stps) 
        : Recipe(n) {
        ingredients = ingr;
        steps = stps;
    }

    // Override the displayRecipe() function for Non-Vegetarian recipes
    void displayRecipe() override {
        cout << "\nNon-Vegetarian Recipe: " << name << endl;
        cout << "Ingredients:" << endl;
        for (const auto& ingredient : ingredients) {
            cout << "- " << ingredient << endl;
        }
        cout << "Steps:" << endl;
        for (const auto& step : steps) {
            cout << "- " << step << endl;
        }
    }
};

// Function to take user input for recipe details
Recipe* createRecipe() {
    string type;
    cout << "Enter the type of recipe (Vegetarian/Non-Vegetarian): ";
    cin >> type;

    cin.ignore(); // Clear the newline character from the input buffer

    string name;
    cout << "Enter the recipe name: ";
    getline(cin, name);

    int ingredientCount;
    cout << "Enter the number of ingredients: ";
    cin >> ingredientCount;
    cin.ignore(); // Clear the newline character from the input buffer

    vector<string> ingredients;
    for (int i = 0; i < ingredientCount; ++i) {
        string ingredient;
        cout << "Enter ingredient " << i + 1 << ": ";
        getline(cin, ingredient);
        ingredients.push_back(ingredient);
    }

    int stepCount;
    cout << "Enter the number of steps: ";
    cin >> stepCount;
    cin.ignore(); // Clear the newline character from the input buffer

    vector<string> steps;
    for (int i = 0; i < stepCount; ++i) {
        string step;
        cout << "Enter step " << i + 1 << ": ";
        getline(cin, step);
        steps.push_back(step);
    }

    // Create the appropriate Recipe object based on user input
    if (type == "Vegetarian") {
        return new VegetarianRecipe(name, ingredients, steps);
    } else if (type == "Non-Vegetarian") {
        return new NonVegetarianRecipe(name, ingredients, steps);
    } else {
        cout << "Invalid recipe type! Defaulting to Vegetarian Recipe." << endl;
        return new VegetarianRecipe(name, ingredients, steps);
    }
}

int main() {
    // Take user input to create a recipe
    Recipe* recipe = createRecipe();

    // Display the recipe using virtual function
    recipe->displayRecipe();

   
    delete recipe;

    return 0;
}
