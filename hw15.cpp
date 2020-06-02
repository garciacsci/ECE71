/* Homework 15*/

/* 
 * File:    hw15.cpp
 * Purpose: Play a simplified dice version of Blackjack.
 * Author:  Christopher Garcia
 * Date:    March 3, 2020
 */

// Preprocessor Directives
#include <cstdlib> 
#include <cmath> 
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Function Prototypes
double getWager(double money);
// Determines an acceptable wager.

void newDeal(int &playerTotal, int &houseTotal,
int &knownHousePoints);
// Responsible for dealing the first two rounds to the player
// and the house.
 
void playerTurn(bool &playerBust, int &playerTotal,
int houseTotal);
// Responsible for dealing cards to the player as long as they
// continue to hit after the first two rounds.
 
void houseTurn(bool &houseBust, int &houseTotal,
int playerTotal);
// Responsible for dealing cards to the house as long as the
// house continues to hit after the first two rounds.
 
void initRNG(void);
// Initializes the random number generator
 
void dealCard(string &card, int &points);
// Deals a single card and returns the name of the card
// and the point value of the card. 

// Define Main Function
int main(int argc, char** argv) 
{
    // Declare Variables
    double money=100, wager;
    int playerTotal, houseTotal, knownHousePoints, points;
    bool playerBust=false, houseBust=false;
    string card;
    char choice, hitOrStand='h';
    
    // Greet player
    cout << "WELCOME TO BLACKJACK\n";
    
    // Set precision, show decimal, and precision two
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    // Tell player their starting money
    cout << "  You have $" << money << "\n";
    
    // Enter loop as long as player wants to play
    do
    {    
    // Get wager
      wager = getWager(money);
    
    // Do a new deal
      newDeal (playerTotal, houseTotal, knownHousePoints);
    
    // Analyze Results of newDeal
      if (playerTotal == 21 && houseTotal == 21)
      {
          cout << "\n\nThe Player and the House were dealt Natural Blackjacks."
               << endl;
          cout << "The Wager is Returned to the Player and no one Wins.";
          cout << "\n\n\tTotal Money:\t\t" << setw(4) << money;
      }
      else if (playerTotal == 21 && houseTotal != 21)
      {
          cout << "\n\nThe Player was Dealt a Natural Blackjack." << endl;
          cout << "The Winnings are 1.5x the Wager" << endl;
          cout << "\n\n\tYou Won:\t\t$" << wager;
          money += wager;
          cout << "\n\tTotal Money:\t$" << money;
      }
      else if (houseTotal == 21 && playerTotal != 21)
      {
          cout << "\n\nThe House was Dealt a Natural Blackjack." << endl;
          cout << "\n\nThe House wins and the Player Forfeits Their Wager." << endl;
          cout << "\n\n\t\t\tLost Wager:\t\t" << "$" << wager;
          money -= wager;
          cout << "\ntTotal Money:\t\t" << "$" << money;
      }
      else if (playerTotal < 21 && houseTotal < 21)
      {
          do
            {
                cout << "\n\nHit or Stand: ";
                cin >> hitOrStand;
                if (playerBust = true)
            {
                cout << "You Busted!";
                cout << "\n\n\t\t\tLost Wager:\t\t" << "$" << wager;
                money -= wager;
                 cout << "\ntTotal Money:\t\t" << "$" << money;
                 break;
            }
            else if (playerTotal == 21)
            {
                cout << "Blackjack!";
                cout << "\n\n\tYou Won:\t\t$" << wager;
                money += wager;
                cout << "\n\tTotal Money:\t$" << money;     
                break;
            }
            else if (hitOrStand == 'h' || hitOrStand == 'H')
                    {
                        playerTurn(playerBust, playerTotal, knownHousePoints);
                    }
            else if (hitOrStand == 's' || hitOrStand == 'S')
                    {   
                        cout << "House Flips Hole Card Over.";  
                        cout << "\n\n   Player Point Total:\t" << setw(2) << \
                                playerTotal;
                        cout << "\n   House Point Total:\t" << setw(2) << \
                                houseTotal;
                        if (houseTotal < 17)
                        {
                            do
                            {
                                houseTurn(houseBust, houseTotal, playerTotal);
                            } while (houseBust = false || houseTotal != 21 || \
                                    houseTotal < 17);
                        }
                    }
            } while (playerBust == false || hitOrStand != 'S' || hitOrStand \
                   != 's' || playerTotal != 21);   
      }
      
      cout << "\n\nPlay Again? (Y/N): ";
      cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    
    // Exit Program
    exit(EXIT_SUCCESS);
}

// Define User Defined Functions
double getWager(double money)
// Determines an acceptable wager.
{
    // Declare variables
    double wager;
    char garbage;
    
    // Prompt for wager
    cout << "\nEnter a wager: ";
    
    // Read in wager
    cin >> garbage >> wager;
    
    // Evaluate Validity of Wager
    do
    if (wager <= money && wager >0)
    {
        cout << "Your wager is: $" << wager;
        return(0);
    }
    else
    {
        cout << "\nError: Invalid Wager" << endl;
        cout << "Please enter a valid wager: ";
        cin >> garbage >> wager;
    }
    while (wager <=0 || wager > money);
    
    cout << "\nYour wager is: $" << wager;
    // Exit Function
    return(0);
}



void newDeal(int &playerTotal, int &houseTotal,
int &knownHousePoints)
// Responsible for dealing the first two rounds to the player
// and the house.
{
    // Declare Variables
    int points;
    string card;
    
    // Initialize totals and points
    playerTotal =0;
    houseTotal = 0;
    knownHousePoints = 0;
    
  // Player Deal One
    
    // Call deal card
    dealCard(card, points);
    
    // Assign Player Total
    playerTotal += points;
    
    // Printing Player Card
    cout << "\n\nYou are Dealt " << card;
    
  // House Deal One
    
    // Call deal Card
    dealCard(card,points);
    
    // Assign House total & house known total
    houseTotal += points;
    knownHousePoints += points;
    
    //Print House Card
    cout << "\nHouse is Dealt " << card;
    
  // Print Totals One
    cout << "\n\n   Player Point Total:\t" << setw(2) << \
            playerTotal;
    cout << "\n   House Point Total:\t" << setw(2) << \
            knownHousePoints;
  
  // Player Deal Two
    
    // Call deal card
    dealCard(card, points);
    
    // Assign Player Total
    playerTotal += points;
    
    // Printing Player Card
    cout << "\n\nYou are Dealt " << card;
    
  // House Deal Two
    
    // Call deal Card
    dealCard(card,points);
    
    // Assign House total
    houseTotal += points;
    
    //Print House Card
    cout << "\nHouse is Dealt a Hole Card";
    
   // Print Totals Two
    cout << "\n\n   Player Point Total:\t" << setw(2) << playerTotal; 
    cout << "\n   House Point Total:\t" << setw(2) << knownHousePoints <<"+";
    
    // Exit Function
    return;
}


void playerTurn(bool &playerBust, int &playerTotal,
int houseTotal)
// Responsible for dealing cards to the player as long as they
// continue to hit after the first two rounds.
{
    // Declare Variables
    int points;
    string card;
    
   // Player Hit
    
    // Call deal card
    dealCard(card, points);
    
    // Assign Player Total
    playerTotal += points;
    
    // Print Player Card
    cout << "\n\nYou are Dealt " << card;
    
    // Print Totals
    cout << "\n\n   Player Point Total:\t" << setw(2) << playerTotal; 
    cout << "\n   House Point Total:\t" << setw(2) << houseTotal <<"+";
    
    // Check to see if player busted
    if (playerTotal > 21)
        playerBust = true;
    else
        playerBust = false;
    
    // Exit Function
    return;
}
 

void houseTurn(bool &houseBust, int &houseTotal,
int playerTotal)
// Responsible for dealing cards to the house as long as the
// house continues to hit after the first two rounds.
{
    // Declare Variables
    int points;
    string card;
    
  // House Hit
    
    // Call deal Card
    dealCard(card,points);
    
    // Assign House total & house known total
    houseTotal += points;
    
    //Print House Card
    cout << "\nHouse is Dealt " << card;
    
  // Print Totals One
    cout << "\n\n   Player Point Total:\t" << setw(2) << \
            playerTotal;
    cout << "\n   House Point Total:\t" << setw(2) << \
            houseTotal;
       
  // Check if House Busted
    if (houseTotal > 21)
        houseBust = true;
    else 
        houseBust = false;
    
    // Exit Function
    return;
}


void initRNG(void)
// Initializes the random number generator
{
    // Seed Random Number Generator
    srand(clock());
    
    // Exit Function
    return;
}

void dealCard(string &card, int &points)
// Deals a single card and returns the name of the card
// and the point value of the card. 
{
    // Declare variables
    int die;
    
    // Call on initRNG Function
    initRNG();
    
    // Generate a random number from 1-13
    die = (rand()%12)+1;
    
    // Return Appropriate name & point value
    switch(die)
    {
        case 0:
            cout << "\n\nThe deal card function generated a zero...\n\n";
            break;
        case 1:
            card = "an Ace";
            points = 11;
            break;
        case 2:
            card = "a Two";
            points = 2;
            break;
        case 3:
            card = "a Three";
            points = 3;
            break;
        case 4:
            card = "a Four";
            points = 4;
            break;
        case 5:
            card = "a Five";
            points = 5;
            break;
        case 6:
            card = "a Six";
            points = 6;
            break;
        case 7: 
            card = "a Seven";
            points = 7;
            break;
        case 8:
            card = "an Eight";
            points = 8;
            break;
        case 9:
            card = "a Nine";
            points = 9;
            break;
        case 10:
            card = "a Ten";
            points = 10;
            break;
        case 11:
            card = "a Jack";
            points = 10;
            break;
        case 12:
            card = "a Queen";
            points = 10;
            break;
        case 13:
            card = "a King";
            points = 10;
        case 14:
            cout << "\n\nThe deal card function generated a 14...\n\n";
            break;
        default:
            cout << "\n\nThe deal card function defaulted...\n\n";
    }
    // Exit Function
    return;
}
