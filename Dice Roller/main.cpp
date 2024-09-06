#include <iostream> 
#include "dice_roller.h"

using namespace std;

// Function to get a valid number of rolls from the user
int getValidNumRolls()
{
    int numRolls;
    cout << "Enter the number of dice to roll: ";
    cin >> numRolls;

    // Validate the number of rolls
    if (numRolls <= 0)
    {
        cerr << "Error: The number of rolls must be greater than zero!" << endl;
        return -1; // Return error value
    }

    return numRolls;
}

// Function to get a valid dice type from the user
string getValidDiceType(DiceRoller& diceRoller) 
{
    string diceType;
    cout << "Enter the type of dice you want to roll (d4, d6, d8, d10, d12, d20, d100): ";
    cin >> diceType;

    // Validate the dice type
    if (!diceRoller.isValidDiceType(diceType))
    {
        return ""; // Return an empty string to indicate an error
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