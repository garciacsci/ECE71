/* Homework 8*/

/* 
 * Name:    hw08.cpp
 * Purpose: print a table of the time, altitude, and the velocity for a weather 
 *          balloon using units of meters and meters per second based on user input.
 * Author:  Christopher Garcia
 * Date:    12 February 2020
 */

// Preprocessor Directives
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

// Define Main Function
int main(int argc, char** argv) {
    //Define Variables
    double time, timeIncrement, endingTime, altitude, velocity, peak=0, peakTime;
    
    // Greet and Prompt the user for and read in the starting time, 
    // time increment, and ending time
    cout << "Welcome to the Weather Balloon Altitude and Velocity Program.\n\n";
    cout << "Enter the Balloon's Starting Time: ";
    cin >> time;
    cout << "Enter the Time Increment: ";
    cin >> timeIncrement;
    cout << "Enter the Balloon's Ending Time: ";
    cin >> endingTime;
    cout << "\n";
    
    // Check that time is valid
    if (time<48 && timeIncrement<48 && endingTime<48)
    {
        // Printing Headers
        cout << "Weather Balloon Information\n";
        cout << "Time (hr)" << "\t" << "Altitude (m)" << "\t" << "Velocity (m/s)\n";
        
        // Enter Loop
        do
        {   
        // Setting output to fixed notation, show decimal point, and always show two places 
       cout.setf(ios::fixed);
       cout.setf(ios::showpoint);
       cout.precision(2);
       
       // Printing Time
       cout << setw(6) << time << "\t\t";
       
        // Calculate Balloon Altitude in meters
        altitude = -0.12 * pow (time,4) + 12 * pow (time,3) - 380 * pow (time,2) + 4100 * time + 220;
        cout.precision(1);
        cout << setw(8) << altitude << "\t";

        //Calculate Balloon Velocity
        velocity = -0.48 * pow (time,3) + 36 * pow (time,2) - 760 * time + 4100;
        velocity = velocity/3600;
        cout.precision(2);
        cout << setw(9) << velocity << "\n";
        
        // Calculate peak and corresponding time
        if (altitude>peak)
        {
        peak = altitude;
        peakTime = time;
        }       
        
        // Incrementing Time
        time += timeIncrement;
        } while (time<endingTime );
        
        // Print Peak Altitude and corresponding Time
        cout << "\n";
        cout.precision(1);
        cout << "Peak Altitude: " << peak << " (m)" << "\n";
        cout.precision(2);
        cout << "Corresponding Time: " << peakTime << " hr";
    }
    else
    {
        
    }
    
    // Exit Program
    return 0;
}
