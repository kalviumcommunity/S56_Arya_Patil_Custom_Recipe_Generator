#include <iostream>
#include <string>
using namespace std;

// Base class Recipe
class Recipe {
public:
    // Virtual method for calculating nutrition
    virtual void calculateNutrition() const = 0;

    // Virtual method for displaying the recipe
    virtual void displayRecipe() const = 0;

    // Virtual destructor
    virtual ~Recipe() {}
};

// Subclass for Vegan Recipe
class VeganRecipe : public Recipe {
private:
    string recipeName;
    int calories;
    int protein;

public:
    // Constructor
    VeganRecipe(string name, int cal, int prot)
        : recipeName(name), calories(cal), protein(prot) {}

    // Overridden method for calculating nutrition for vegan recipes
    void calculateNutrition() const override {
        cout << "Vegan Recipe: " << recipeName << endl;
        cout << "Calories: " << calories << " kcal" << endl;
        cout << "Protein: " << protein << " g" << endl;
    }

    // Overridden method for displaying the recipe
    void displayRecipe() const override {
        cout << "Recipe Name: " << recipeName << endl;
        cout << "This is a delicious vegan recipe!" << endl;
    }
};

// Subclass for Gluten-Free Recipe
class GlutenFreeRecipe : public Recipe {
private:
    string recipeName;
    int calories;
    int carbs;

public:
    // Constructor
    GlutenFreeRecipe(string name, int cal, int carb)
        : recipeName(name), calories(cal), carbs(carb) {}

    // Overridden method for calculating nutrition for gluten-free recipes
    void calculateNutrition() const override {
        cout << "Gluten-Free Recipe: " << recipeName << endl;
        cout << "Calories: " << calories << " kcal" << endl;
        cout << "Carbs: " << carbs << " g" << endl;
    }

    // Overridden method for displaying the recipe
    void displayRecipe() const override {
        cout << "Recipe Name: " << recipeName << endl;
        cout << "This recipe is perfect for those on a gluten-free diet!" << endl;
    }
};

int main() {
    int recipeType;

    // Ask user for the type of recipe
    cout << "Choose Recipe Type:" << endl;
    cout << "1. Vegan Recipe" << endl;
    cout << "2. Gluten-Free Recipe" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> recipeType;

    cin.ignore();  // To clear the buffer before reading a string

    string recipeName;
    int calories, proteinOrCarbs;

    // Take input for recipe details based on recipe type
    if (recipeType == 1) {  // Vegan Recipe
        cout << "Enter Recipe Name: ";
        getline(cin, recipeName);
        cout << "Enter Calories: ";
        cin >> calories;
        cout << "Enter Protein (grams): ";
        cin >> proteinOrCarbs;

        // Create VeganRecipe object and display it
        Recipe* veganRecipe = new VeganRecipe(recipeName, calories, proteinOrCarbs);
        veganRecipe->displayRecipe();
        veganRecipe->calculateNutrition();

        delete veganRecipe;  // Clean up dynamically allocated memory
    }
    else if (recipeType == 2) {  // Gluten-Free Recipe
        cout << "Enter Recipe Name: ";
        getline(cin, recipeName);
        cout << "Enter Calories: ";
        cin >> calories;
        cout << "Enter Carbs (grams): ";
        cin >> proteinOrCarbs;

        // Create GlutenFreeRecipe object and display it
        Recipe* glutenFreeRecipe = new GlutenFreeRecipe(recipeName, calories, proteinOrCarbs);
        glutenFreeRecipe->displayRecipe();
        glutenFreeRecipe->calculateNutrition();

        delete glutenFreeRecipe;  // Clean up dynamically allocated memory
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
