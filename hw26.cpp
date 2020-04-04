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
#include <string>
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
int numInRank[NUM_RANKS] = {0};
// Array representing the number of a given rank in hand 
// numInRank[0] represents number of 2’s 
// numInRank[1] represents number of 3’s 
// ... 
// numInRank[12] represents number of Aces

int numInSuit[NUM_SUITS] = {0};  
// Array representing the number of a given suit in hand 
// numInSuit[0] represents number of Clubs 
// numInSuit[1] represents number of Diamonds 
// numInSuit[2] represents number of Hearts 
// numInSuit[3] represents number of Spades

bool Royal = false;
//set true if player has a Royal Flush

bool Flush = false;
// Set true if player has a Flush

bool Straight = false;
// Set true if player has a Straight

bool Four = false;
// Set true if player has a Four of a Kind

bool Three = false;
// Set true if player has Three of a Kind

int Pairs = 0;
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
    bool cardExists[NUM_RANKS][NUM_SUITS] = {false};
    string card;
    int rank, suit, count = 1;
    
    do
    {    
        while  (count <= NUM_CARDS)
        {                        
            // Prompt for and read in card from user
            cout << "Enter Card " << count << ": ";
            cin >> card;

            // Check to see if string is too long
            if (card.length() != 2)
            {
                cout << "Ignoring bad card.\n\n";
                break;
            }

            // Convert to corresponding integer and check for invalid rank
            if(card.at(0) == '2')    
                rank = 0;
            else if (card.at(0) == '3')
                rank = 1;
            else if (card.at(0) == '4')
                rank = 2;   
            else if (card.at(0) == '5')
                rank = 3;  
            else if (card.at(0) == '6')
                rank = 4;  
            else if (card.at(0) == '7')
                rank = 5;  
            else if (card.at(0) == '8')
                rank = 6;  
            else if (card.at(0) == '9')
                rank = 7;  
            else if (card.at(0) == 't' || card.at(0) == 'T')
                rank = 8;  
            else if (card.at(0) == 'j' || card.at(0) == 'J')
                rank = 9;
            else if (card.at(0) == 'q' || card.at(0) == 'Q')
                rank = 10;  
            else if (card.at(0) == 'k' || card.at(0) == 'K')
                rank = 11;  
            else if (card.at(0) == 'a' || card.at(0) == 'A')
                rank = 12;  
            else
            {
                cout << "Ignoring bad card.\n\n";
                break;
            }

            // Convert to corresponding integer and check for invalid integer
            if (card.at(1) == 'c' || card.at(1) == 'C')
                suit = 0;
            else if (card.at(1) == 'd' || card.at(1) == 'D')
                suit = 1;
            else if (card.at(1) == 'h' || card.at(1) == 'H')
                suit = 2;
            else if (card.at(1) == 's' || card.at(1) == 'S')
                suit = 3;
            else
            {
                cout << "Ignoring bad card.\n\n";
                break;
            }

            // Check if card exists and increment numInRank/Suit accordingly
            if (cardExists[rank][suit] == false)
            {
                cardExists[rank][suit] = true;
                numInRank[rank]++;
                // Track pairs
                if (numInRank[rank] == 2 || numInRank[rank] == 4)
                    Pairs ++;
                numInSuit[suit]++;
                count++;
            }
            else
            {
                cout << "Ignoring duplicate card.\n\n";
                break;
            }
        }        
    } while (count <= NUM_CARDS);
                
    // Exit function
    return;
}


//----------------------------------------------------------------------------//


void analyzeHand(void)
{
// Declare variables
int tally = 0, x = 0;

// Determine possible hands
for (int i = 0; i < NUM_SUITS; i++)
    {
        // Check for Flush
        if (numInSuit[i] == NUM_CARDS)
        {            
            Flush = true;
                for (int c = NUM_RANKS-1; c >= 4; c--)
                {
                    // Check for royal flush
                    tally += numInRank[c] + numInRank[c-1] + numInRank[c-2] + \
                            numInRank[c-3] + numInRank[c-4];
                                        
                    if (tally == 5 && c == NUM_RANKS - 1)
                        Royal = true;       
                    else if (tally == 5 && c < NUM_RANKS - 1)
                        Straight = true;
                    
                    tally = 0;
                    
                }                
        }
        
        else
        {            
            for (int c = NUM_RANKS; c > 4; c--)
                {
                    // Check for straight
                    tally += numInRank[c] + numInRank[c-1] + numInRank[c-2] + \
                            numInRank[c-3] + numInRank[c-4];

                    if (tally == 5)
                        Straight = true;       

                    tally = 0;
                }
            
             for (int c = NUM_RANKS; c > -1; c--)
                {
                    // Check for four of a kind
                    tally += numInRank[c];

                    if (tally == 4)
                        Four = true;       

                    tally = 0;

                    // Check for three of a kind
                    tally += numInRank[c];

                    if (tally == 3)
                        Three = true;       

                    tally = 0;
                }             
        }
    }
    
    // Exit function
    return;       
}


//----------------------------------------------------------------------------//


void printResults(void)
{
    // Declare variables
    string bh;
    
    // Determine best hand
    if (Royal)
        bh = "Royal Flush";
    else if (Flush && Straight)
        bh = "Straight Flush";
    else if (Four)
        bh = "Four of a Kind";
    else if (Three && Pairs == 2)
        bh = "Full House";
    else if (Flush && !Straight)
        bh = "Straight";
    else if (Three && Pairs == 1)
        bh = "Three of a Kind";
    else if (Pairs == 2 && !Three && !Four)
        bh = "Two Pairs";
    else if (Pairs == 1 && !Three && !Four)
        bh = "One Pair";
    else
        bh = "High Card";
    
    // Print best hand
    cout << "Best Hand: " << bh;
        
    // Exit function
    return;    
} 
