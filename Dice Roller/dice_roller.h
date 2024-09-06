#ifndef DICE_ROLLER_H
#define DICE_ROLLER_H

#include <string>

class DiceRoller 
{
    public:
        // Constructor to initialize random seed
        DiceRoller();

        // Function to roll a single die with given number of sides
        int rollDie(int sides);

        // Function to roll multiple dice based on dice type and number of rolls
        void rollDice(const std::string& diceType, int numRolls);

        // Function to check if the dice type is valid
        bool isValidDiceType(const std::string& diceType);

    private:
        // Helper function to get the number of sides for a given dice type
        int getDiceSides(const std::string& diceType);
};

#endif // DICE_ROLLER_H