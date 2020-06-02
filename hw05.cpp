/* Homework 5*/

/* 
 * Name:    hw05.cpp
 * Purpose: Tell the user where a pair of variables are if the variables x and y are plotted on a y versus x graph.
 * Author:  Christopher Garcia
 * Date:    12 February 2020
 */

// Preprocessor Directives
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

//Define main function
int main(int argc, char** argv)
{
//Declare Variables
    double x, y;
    
// Prompt user and read input
    cout << "Input Coordinate Pair: ";
    cin >> x;
    cin >> y;
    
// Determine and Print out Coordinate Position
    if (x==0 && y==0) 
    {
        cout << "Origin";
    }
    else if (x==0 && y>0)
    {
        cout << "Positive y Axis";
    }
    else if (x==0 && y<0)
    {
        cout << "Negative y Axis";
    }   
    else if (x>0 && y==0)
    {
        cout << "Positive x Axis";
    }
    else if (x<0 && y==0)
    {
        cout << "Negative x Axis";
    }
    else if (x>0 && y>0)
    {
        cout << "Quadrant 1";
    }
    else if (x<0 && y>0)
    {
        cout << "Quadrant 2";
    }
    else if (x<0 && y<0)
    {
        cout << "Quadrant 3";
    }
    else if (x>0 && y<0)
    {
        cout << "Quadrant 4";
    }    
    else
    {
        cout << "How did you even get this???";
    }
    
    // Exit Program
    return 0;
}
