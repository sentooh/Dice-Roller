#include "dice_roller.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constants to define valid dice types
const int MIN_DICE_SIDES = 4;
const int MAX_DICE_SIDES = 100;

// Constructor initializes random seed
DiceRoller::DiceRoller() 
{
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
}

// Function to roll a single die
int DiceRoller::rollDie(int sides) 
{
    // Ensure the number of sides is valid
    if (sides < MIN_DICE_SIDES || sides > MAX_DICE_SIDES)
    {
        cerr << "Error: Invalid number of sides (" << sides << ")!" << endl;
        return -1; // Return an error value
    }
    return rand() % sides + 1; // Random number between 1 and sides
}

// Helper function to convert dice type to number of sides
int DiceRoller::getDiceSides(const std::string& diceType)
{
    if (diceType == "d4") return 4;
    else if (diceType == "d6") return 6;
    else if (diceType == "d8") return 8;
    else if (diceType == "d10") return 10;
    else if (diceType == "d12") return 12;
    else if (diceType == "d20") return 20;
    else if (diceType == "d100") return 100;
    else return 0; // Invalid dice type
}

// Function to validate the dice type input
bool DiceRoller::isValidDiceType(const std::string& diceType) 
{
    int sides = getDiceSides(diceType);
    if(sides == 0) 
    {
        cout << "Error: Invalid dice type (" << diceType << ")!" << endl;
        return false;
    }
    return true;
}

// Function to roll multiple dice and print the results
void DiceRoller::rollDice(const std::string& diceType, int numRolls) 
{
    // Validate dice type
    if (!isValidDiceType(diceType))
    {
        return; // Early return on valid input
    }

    int sides = getDiceSides(diceType);

    // Validate the number of rolls
    if (numRolls <= 0)
    {
        cerr << "Error: The number of rolls must be greater than zero!" << endl;
        return;
    }
    
    cout << "Rolling " << numRolls << " " << diceType << "(s)..." << endl;
    for (int i = 0; i < numRolls; ++i)
    {
        int result = rollDie(sides);
        if (result != -1) 
        {
            // Only print valid roll results
            cout << "Roll " << i + 1 << ": " << result << endl;
        }
    }
}