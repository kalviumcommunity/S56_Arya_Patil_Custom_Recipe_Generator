#include <iostream>
#include <string>

//static int recipeCount;
//static int nextRecipeID;
//recipeCount: Keeps track of the total number of Recipe objects created.
//nextRecipeID: Provides a unique ID for each Recipe object.
//These variables are declared as static, meaning that:

//Shared Across All Objects: They are shared among all instances of the Recipe class. There is only one copy of these variables, regardless of how many Recipe objects are created.
//Persistent Across Function Calls: Their values persist across different function calls and object creations.

class Recipe {
private:
    static int recipeCount;
    static int nextRecipeID;
    int recipeID;
    std::string recipeName;

public:
    // Constructor to initialize recipe with a name
    Recipe(std::string name) : recipeName(name) {
        recipeID = nextRecipeID++;  // Assign a unique ID to each recipe
        recipeCount++;  // Increment the total recipe count
    }

    // Method to display recipe details
    void displayRecipe() const {
        std::cout << "Recipe ID: " << recipeID << "\nRecipe Name: " << recipeName << std::endl;
    }

    // Static method to display the total number of recipes created
    static void displayTotalRecipes() {
        std::cout << "Total Recipes Created: " << recipeCount << std::endl;
    }
};

// Initialize static members outside the class
int Recipe::recipeCount = 0;
int Recipe::nextRecipeID = 1;

int main() {
    int numberOfRecipes;
    std::string recipeName;

    std::cout << "Enter the number of recipes you want to create: ";
    std::cin >> numberOfRecipes;

    Recipe** recipes = new Recipe*[numberOfRecipes];  // Dynamic array of Recipe pointers

    for (int i = 0; i < numberOfRecipes; ++i) {
        std::cout << "Enter name for recipe " << (i + 1) << ": ";
        std::cin >> recipeName;
        recipes[i] = new Recipe(recipeName);  // Create a new Recipe object dynamically
    }

    std::cout << "\n--- Recipes Created ---\n";
    for (int i = 0; i < numberOfRecipes; ++i) {
        recipes[i]->displayRecipe();
        std::cout << std::endl;
    }

    // Display total recipes
    Recipe::displayTotalRecipes();

    // Clean up dynamically allocated memory
    for (int i = 0; i < numberOfRecipes; ++i) {
        delete recipes[i];  // Delete each dynamically allocated Recipe object
    }
    delete[] recipes;  // Delete the array of pointers

    return 0;
}
