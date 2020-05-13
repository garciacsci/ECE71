/* Declares a “boulder” class to store relevant boulder information */

#ifndef BOULDER_HPP
#define BOULDER_HPP

class Apple
{
    
public:
    // Default Constructor
     Boulder();

     // Constructor with color initialization
     Boulder(int c);

     // Function to help create a new apple
     void newBoulder(int c);
     
     // Clears boulders from the board
     void clearBoulder();
     
};


#endif /* BOULDER_HPP */
