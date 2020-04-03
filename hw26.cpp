/* Homework 26*/

/* 
 * File:    hw26.cpp
 * Author:  Christopher Garcia
 * Purpose: Analyze a poker hand for 5 card stud 
 * Date:    April 2, 2020
 */

// Preprocessor Directives
#include <cstdlib> 
#include <cmath> 
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;



//----------------------------------------------------------------------------//



// Declare and initialize constants
const int NUM_RANKS = 13;
// Stores number of ranks in a deck(13)

const int NUM_SUITS = 4;
// Stores number suits in a deck(4)'

const int NUM_CARDS = 5;
// Stores number of cards to be played(5)



//----------------------------------------------------------------------------//



// Declare global variables
int numInRank[NUM_RANKS];
// Array representing the number of a given rank in hand 
// numInRank[0] represents number of 2’s 
// numInRank[1] represents number of 3’s 
// ... 
// numInRank[12] represents number of Aces

int numInSuit[NUM_SUITS];  
// Array representing the number of a given suit in hand 
// numInSuit[0] represents number of Clubs 
// numInSuit[1] represents number of Diamonds 
// numInSuit[2] represents number of Hearts 
// numInSuit[3] represents number of Spades

bool Royal;
//set true if player has a Royal Flush

bool Flush;
// Set true if player has a Flush

bool Straight;
// Set true if player has a Straight

bool Four;
// Set true if player has a Four of a Kind

int Pairs;
// Counts number of Pairs in Hand



//----------------------------------------------------------------------------//



// Function Prototypes
void readCards(void);
// Read in 5 cards, Ignoring Bad/Repeated Cards 

void analyzeHand(void);
// Analyze cards for Different Hands to Play 

void printResults(void);
// Print the Best Hand 




//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//




int main(int argc, char** argv) 
{
    // Greet the user
    cout << "Welcome to the 5 Card Stud Analyzer Program" << endl;
    
    // Read cards
    cout << endl;
    readCards();
    
    // Analyze hand
    analyzeHand();
    
    // Print Results
    cout << endl;
    printResults();

    // Exit Program
    exit(EXIT_SUCCESS);
}




//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//
//----------------------------------------------------------------------------//




// Define user-defined functions
void readCards(void)
{
    // Declare variables
    bool cardExists[NUM_RANKS][NUM_SUITS]; 
    
    // Exit function
    return;
}


//----------------------------------------------------------------------------//


void analyzeHand(void)
{
    
    // Exit function
    return;       
}


//----------------------------------------------------------------------------//


void printResults(void)
{
    // Exit function
    return;    
}
