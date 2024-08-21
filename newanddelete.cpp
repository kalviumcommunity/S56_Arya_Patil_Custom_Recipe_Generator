#include <iostream>
#include <string>

class Ingredient {
public:
    std::string name;
    float quantity;

    // Default constructor
    Ingredient() : name(""), quantity(0) {}

    // Parameterized constructor
    Ingredient(std::string name, float quantity) : name(name), quantity(quantity) {}
};

class Recipe {
private:
    Ingredient* ingredients;
    int numIngredients;

public:
    // Constructor to allocate dynamic memory
    Recipe(int num) : numIngredients(num) {
        ingredients = new Ingredient[num];
    }

    // Function to add an ingredient
    void addIngredient(int index, const std::string& name, float quantity) {
        if (index >= 0 && index < numIngredients) {
            ingredients[index] = Ingredient(name, quantity);
        } else {
            std::cout << "Index out of bounds!" << std::endl;
        }
    }

    // Function to display the recipe
    void showRecipe() {
        for (int i = 0; i < numIngredients; i++) {
            std::cout << "Ingredient " << i + 1 << ": " << ingredients[i].name 
                      << " - " << ingredients[i].quantity << std::endl;
        }
    }

    // Destructor to deallocate dynamic memory
    ~Recipe() {
        delete[] ingredients;
    }
};

int main() {
    int numIngredients;

    // Prompting user for the number of ingredients
    std::cout << "Enter the number of ingredients in the recipe: ";
    std::cin >> numIngredients;

    // Creating a Recipe object with the specified number of ingredients
    Recipe myRecipe(numIngredients);

    std::string name;
    float quantity;

    // Clearing input buffer before taking string input
    std::cin.ignore();

    // Loop to input each ingredient
    for (int i = 0; i < numIngredients; i++) {
        std::cout << "Enter name of ingredient " << i + 1 << ": ";
        std::getline(std::cin, name);  // Using std::getline to handle spaces in names
        std::cout << "Enter quantity of " << name << ": ";
        std::cin >> quantity;
        std::cin.ignore();  // To clear the newline character left in the buffer
        myRecipe.addIngredient(i, name, quantity);
    }

    // Displaying the recipe
    myRecipe.showRecipe();

    return 0;
}
