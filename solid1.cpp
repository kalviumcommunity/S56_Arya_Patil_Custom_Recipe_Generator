#include <iostream>
#include <string>
#include <vector>
#include <ctime> // Include this for time()

using namespace std;

// Class to store and manage recipe details
class Recipe {
private:
    string name;
    vector<string> ingredients;
    int cookingTime; // in minutes

public:
    Recipe(string recipeName, vector<string> recipeIngredients, int time)
        : name(recipeName), ingredients(recipeIngredients), cookingTime(time) {}

    // Method to display the recipe details
    void displayRecipe() const {
        cout << "Recipe: " << name << "\nCooking Time: " << cookingTime << " minutes\nIngredients:\n";
        for (const auto& ingredient : ingredients) {
            cout << "- " << ingredient << "\n";
        }
        cout << endl;
    }
};

// Class for generating a random custom recipe
class RecipeGenerator {
private:
    vector<Recipe> recipes;

public:
    // Method to add a recipe to the generator
    void addRecipe(const Recipe& recipe) {
        recipes.push_back(recipe);
    }

    // Method to randomly select and return a recipe
    Recipe getRandomRecipe() const {
        if (recipes.empty()) {
            throw runtime_error("No recipes available.");
        }
        int index = rand() % recipes.size(); // Generate a random index
        return recipes[index];
    }
};

// Function to take user input and create a new Recipe
Recipe createRecipeFromUserInput() {
    string name;
    vector<string> ingredients;
    int cookingTime, numIngredients;

    cout << "Enter the recipe name: ";
    getline(cin, name);

    cout << "Enter the cooking time (in minutes): ";
    cin >> cookingTime;
    cin.ignore(); // Ignore newline left in the buffer

    cout << "Enter the number of ingredients: ";
    cin >> numIngredients;
    cin.ignore(); // Ignore newline left in the buffer

    cout << "Enter the ingredients one by one:\n";
    for (int i = 0; i < numIngredients; ++i) {
        string ingredient;
        cout << "Ingredient " << (i + 1) << ": ";
        getline(cin, ingredient);
        ingredients.push_back(ingredient);
    }

    return Recipe(name, ingredients, cookingTime);
}

int main() {
    // Seed for random number generation
    srand(static_cast<unsigned int>(time(0))); // Use current time as seed for random generator

    // Creating RecipeGenerator object
    RecipeGenerator generator;

    // Option to add recipes manually
    int choice;
    cout << "Welcome to the Custom Recipe Generator!\n";
    cout << "How many recipes would you like to add? ";
    cin >> choice;
    cin.ignore(); 

    for (int i = 0; i < choice; ++i) {
        cout << "\nEnter details for Recipe " << (i + 1) << ":\n";
        Recipe recipe = createRecipeFromUserInput();
        generator.addRecipe(recipe);
    }

    // Generating and displaying a random recipe
    cout << "\nGenerating a random recipe...\n";
    try {
        Recipe randomRecipe = generator.getRandomRecipe();
        randomRecipe.displayRecipe();
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
