#include <iostream> 
#include "dice_roller.h"
#include <cstdlib> // For system()
#include <limits>  // For std::numeric_limits

using namespace std;

// Function to get a valid number of rolls from the user
int getValidNumRolls()
{
    int numRolls;

    while (true)
    {
        cout << "Enter the number of dice to roll: ";
        cin >> numRolls;

        // Check if the input was invalid (i.e., not an integer)
        if (cin.fail())
        {
            cin.clear(); // Clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Error: Please enter a valid number!" << endl;
        }
        // Validate the number of rolls
        else if (numRolls <= 0)
        {
            cerr << "Error: The number of rolls must be greater than zero!" << endl;
        }
        else
        {
            return numRolls; // Valid input, return the number of rolls
        }
    }
}

// Function to get a valid dice type from the user
string getValidDiceType(DiceRoller& diceRoller) 
{
    string diceType;

    // Keep asking for input until a valid dice type is entered
    while (true)
    {
        cout << "Enter the type of dice you want to roll (d4, d6, d8, d10, d12, d20, d100): ";
        cin >> diceType;

        // Validate the dice type
        if (!diceRoller.isValidDiceType(diceType))
        {
            cout << "Invalid dice type! Please enter a valid dice type (d4, d6, d8, d10, d12, d20, d100)." << endl;
        }

        else 
        {
            break; // Exit the loop when a valid dice type is entered
        }
    }
    
    return diceType;
}

// Function to ask the user if they want to roll again
bool askToRollAgain() 
{
    char choice;
    
    // Loop until valid input is received
    while (true) 
    {
        cout << "Would you like to roll again? (y/n): ";
        cin >> choice;

        // Check for valid input
        if (choice == 'y' || choice == 'Y')
        {
            return true; // User wants to roll again
        }
        else if (choice == 'n' || choice == 'N')
        {
            return false; // User does not wnat to roll again
        }
        else 
        {
            cout << "Invalid choice. Please enter 'y' for yes or 'n' for no." << endl;
        }
    }
}

// Function to clear the terminal screen
void clearScreen() 
{
    #ifdef _WIN32
        system("cls"); // For Windows
    #else   
        system("clear"); // For Unix-based systems
    #endif
}

// Function to pause execution until the user presses a key
void waitForUserInput()
{
    cout << "Pres any key to exit..." << endl;
    cin.ignore();  // Discard any leftover characters in the input buffer
    cin.get();     // Wait for the user to press a key
}

int main() 
{
    DiceRoller diceRoller; // Create a DiceRoller object
    bool rollAgain = true; // Flag to control the loop

    while (rollAgain)
    {
        // Get valid dice type from the user
        string diceType = getValidDiceType(diceRoller);
        if (diceType.empty())
        {
            return 1; // Exit on invalid input
        }

        // Get valid number of rolls from the user
        int numRolls = getValidNumRolls();
        if (numRolls == -1) 
        {
            return 1; // Exit on invalid input
        }

        // Roll the dice and display the results
        diceRoller.rollDice(diceType, numRolls);

        // Ask if the user wants to roll again
        rollAgain = askToRollAgain();
    }

    // Clear the terminal screen before showing the thank you message
    clearScreen();

    cout << "Thank you for using the dice roller!" << endl;

    // Wait for the user to press any key before exiting
    waitForUserInput();

    return 0;
}