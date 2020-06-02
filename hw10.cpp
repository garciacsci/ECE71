/* Homework 10*/

/* 
 * Name:    hw10.cpp
 * Purpose: Simulates a game of craps
 * Author:  Christopher Garcia
 * Date:    15 February 2020
 */

// Preprocessor Directives
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

// Function Prototypes
int rollDice(void);
bool playGame(void);

int main(int argc, char** argv) {
// Declare Variables
    unsigned int seed;
    int wins, losses;
    bool winOrLose;
    char response;
    
// Welcome the user
    cout << "Welcome to Craps\n\n";
    
// Ask for and read in the seed
    cout << "Please enter a random seed: ";
    cin >> seed;
    cout << "\n";
            
// Use the seed to seed the random number generator
    srand(seed);
    
// Initialize wins and losses
    wins = 0;
    losses = 0;
    
    do
    {
// Call on the play game function and store 
    winOrLose = playGame();
    if (winOrLose == true)
    {
        wins++;
        cout << "\nYou WIN!\n";
    }
    else
    {
        losses++;
        cout << "\nYou Lose!\n";
    }
    
// Ask the user if they want to play again and read in their response
    cout << "\nPlay again? (Y/N): ";
    cin >> response;
    cout << "\n";
    } while (response == 'Y' || response == 'y');
    
    
// Print wins and losses totals
    cout << "Wins:\t" << setw(2) << wins;
    cout << "\nLosses:\t" << setw(2) << losses;
    
// Exit Program
    exit (EXIT_SUCCESS);
}

int rollDice(void)
{
    int r1, r2;
    r1 = (rand()%6)+1;
    r2 = (rand()%6)+1;
    return (r1+r2);
}

bool playGame(void)
{
    // Declare Variables
    int rollResult, point;
    
    // Store roll result
    rollResult = rollDice();
    
    // Print result
    cout << "You rolled:\t" << setw(2) << rollResult << "\n";
    
    // Check for win or loss or point
    if (rollResult == 7 || rollResult == 11)
    {
        return (true);
    }
    else if (rollResult == 2 || rollResult == 3 || rollResult == 12)
    {
        return (false);
    }
    else
    {
        point = rollResult;
        cout << "Your point:\t" << setw(2) << point << "\n\n";
        // Point Loop
         do
         {
             // Roll Dice and Print Result
                rollResult = rollDice();
                cout << "You rolled:\t" << setw(2) << rollResult << "\n";
                
            // Check for win or loss or other roll
                if (rollResult == 7)
                {
                    return (false);
                }
                if (rollResult == point)
                {
                    return (true);
                }
         } while (rollResult != 7 && rollResult != point);
         }
    return (false);    
}
