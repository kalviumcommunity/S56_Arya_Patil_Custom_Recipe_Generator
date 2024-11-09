#include <iostream>
#include <string>
using namespace std;

// Abstract class: LegalService (with at least one pure virtual function)
class LegalService {
public:
    // Pure virtual function (makes this class abstract)
    virtual void serviceDetails() = 0;

    // Virtual destructor to ensure proper cleanup
    virtual ~LegalService() {
        cout << "LegalService: Destructor called." << endl;
    }
};

// Derived class: Consultation
class Consultation : public LegalService {
private:
    string clientName;
    int duration;  // in minutes

public:
    Consultation(string name, int time) : clientName(name), duration(time) {}

    void serviceDetails() override {
        cout << "Consultation Service\n";
        cout << "Client: " << clientName << "\nDuration: " << duration << " minutes\n";
    }

    ~Consultation() {
        cout << "Consultation: Destructor called." << endl;
    }
};

// Derived class: Representation
class Representation : public LegalService {
private:
    string clientName;
    string caseType;

public:
    Representation(string name, string type) : clientName(name), caseType(type) {}

    void serviceDetails() override {
        cout << "Representation Service\n";
        cout << "Client: " << clientName << "\nCase Type: " << caseType << "\n";
    }

    ~Representation() {
        cout << "Representation: Destructor called." << endl;
    }
};

int main() {
    int choice;
    string name, caseType;
    int duration;

    cout << "Select the type of legal service:\n";
    cout << "1. Consultation\n";
    cout << "2. Representation\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    LegalService* service = nullptr;  // Pointer to abstract class

    if (choice == 1) {
        cout << "Enter client name: ";
        cin >> ws;  // To clear input buffer
        getline(cin, name);
        cout << "Enter duration (in minutes): ";
        cin >> duration;

        service = new Consultation(name, duration);  // Polymorphism in action
    } 
    else if (choice == 2) {
        cout << "Enter client name: ";
        cin >> ws;
        getline(cin, name);
        cout << "Enter case type: ";
        getline(cin, caseType);

        service = new Representation(name, caseType);  // Polymorphism in action
    } 
    else {
        cout << "Invalid choice! Exiting...\n";
        return 1;
    }

    // Display service details using the virtual function
    service->serviceDetails();

    // Cleanup
    delete service;

    return 0;
}
