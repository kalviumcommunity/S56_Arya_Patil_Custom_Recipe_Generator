#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Abstract base class
class Recipe {
private:
    string recipeName;        // private data member
    vector<string> ingredients;  // private data member
    vector<string> instructions;  // private data member

protected:
    // Protected methods to set private data
    void setRecipeName(const string& name) {
        recipeName = name;
    }

    void setIngredients(const vector<string>& ing) {
        ingredients = ing;
    }

    void setInstructions(const vector<string>& instr) {
        instructions = instr;
    }

    string getRecipeName() const {
        return recipeName;
    }

    vector<string> getIngredients() const {
        return ingredients;
    }

    vector<string> getInstructions() const {
        return instructions;
    }

public:
    // Abstract methods (pure virtual functions)
    virtual void displayRecipe() const = 0;
};

// Derived class
class CustomRecipe : public Recipe {
public:
    CustomRecipe(const string& name, const vector<string>& ing, const vector<string>& instr) {
        setRecipeName(name);
        setIngredients(ing);
        setInstructions(instr);
    }

    void displayRecipe() const override {
        cout << "Recipe Name: " << getRecipeName() << endl;
        cout << "Ingredients:" << endl;
        for (const auto& ingredient : getIngredients()) {
            cout << "- " << ingredient << endl;
        }
        cout << "Instructions:" << endl;
        for (size_t i = 0; i < getInstructions().size(); ++i) {
            cout << (i + 1) << ". " << getInstructions()[i] << endl;
        }
    }
};

int main() {
    string name;
    int numIngredients, numInstructions;
    vector<string> ingredients;
    vector<string> instructions;

    // User input
    cout << "Enter recipe name: ";
    getline(cin, name);

    cout << "Enter number of ingredients: ";
    cin >> numIngredients;
    cin.ignore(); // To ignore newline character left by cin

    cout << "Enter ingredients (one per line):" << endl;
    for (int i = 0; i < numIngredients; ++i) {
        string ingredient;
        getline(cin, ingredient);
        ingredients.push_back(ingredient);
    }

    cout << "Enter number of instructions: ";
    cin >> numInstructions;
    cin.ignore(); // To ignore newline character left by cin

    cout << "Enter instructions (one per line):" << endl;
    for (int i = 0; i < numInstructions; ++i) {
        string instruction;
        getline(cin, instruction);
        instructions.push_back(instruction);
    }

    // Create a CustomRecipe object with user input
    CustomRecipe myRecipe(name, ingredients, instructions);

    // Display the recipe
    myRecipe.displayRecipe();

    return 0;
}
