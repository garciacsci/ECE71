/* Homework 14*/

/* 
 * File:    hw14.cpp
 * Purpose: Inputs a date and outputs the date in mm/dd/yy format as well
 *          as the day of the week that corresponds to that date.
 * Author:  Christopher Garcia
 * Date:    March 3, 2020
 */

// Preprocessor Directives
#include <cstdlib> 
#include <cmath> 
#include <iostream>
#include <iomanip>

using namespace std;

// Function Prototypes
 void getInput(int &month, int &day, int &year);
 /* Precondition:   the month is entered in via text in either full or 
  *                 abbreviated form                      
 * Postcondition:  
 *                 
 * Purpose:         read in the month, day, and year from the keyboard
 *                  and convert the string for the month into an appropriate
 *                  integer value
 */
 
 bool isLeapYear(int year);
 /* Precondition:   
 *                                  
 * Postcondition:   
 * Purpose:         returns a boolean value that is true if the year is 
 *                  a leap year and false if it is not a leap year
 * 
 */
 
 int getCenturyValue(int year);
 /* Precondition:   
 *                                  
 * Postcondition:  
 *                 
 * Purpose:         take the first two digits of the year variable (that is, 
 *                  the century), divide by 4, and save the remainder. 
 *                  The remainder should then be subtracted from 3 and the
 *                  subsequent value multiplied by 2
 * 
 */
 
 int getYearValue(int year);
 /* Precondition:   
 *                                  
 * Postcondition:  
 *                 
 * Purpose:         computes a value based on the years since the beginning 
 *                  of the century
 * 
 */
 
 int getMonthValue(int month, int year);
 /* Precondition:   
 *                                  
 * Postcondition:  
 *                 
 * Purpose:         returns an integer based on the month and whether
 *                  it is a leap year or not
 * 
 */
 
 string dayOfWeek(int month, int day, int year);
 /* Precondition:   
 *                                  
 * Postcondition:  
 *                 
 * Purpose:         compute the day of the week
 * 
 */
 
// Define Main Function
int main(int argc, char** argv)
{
    // Declare Variables
    int month, day, year;
    
    // Prompt for date
    cout << "Enter a date: ";
    
    // Read in date
    getInput(month, day, year);
    
    // Output date and day of date
    cout << setfill('0') << setw(2) << month << "/" << setfill('0') 
         << setw(2) << day << "/" << setfill('0') << setw(2) 
         << (year - (year/100*100)) << " is a " << dayOfWeek(month, day, year)
         << ".";
    
    // Exit Program
    exit(EXIT_SUCCESS);
}

// Define User Defined Functions
 void getInput(int &month, int &day, int &year)
 {
    // Declare variables
     string monthText, g;
     
     // Read in date
     cin >> monthText >> day >> g >> year;
     
     // Translate month string to corresponding integer
     if (monthText == "Jan" || monthText == "January")
        {
         month = 1;
        }
     else if (monthText == "Feb" || monthText == "Febuary")
        {
         month = 2;
        }
     else if (monthText == "Mar" || monthText == "March")
        {
         month = 3;
        }
     else if (monthText == "Apr" || monthText == "April")
        {
         month = 4;
        }
     else if (monthText == "May")
        {
         month = 5;
        }
     else if (monthText == "Jun" || monthText == "June")
        {
         month = 6;
        }
     else if (monthText == "Jul" || monthText == "July")
        {
         month = 7;
        }
     else if (monthText == "Aug" || monthText == "August")
        {
         month = 8;
        }
     else if (monthText == "Sep" || monthText == "September")
        {
         month = 9;
        }
     else if (monthText == "Oct" || monthText == "October")
        {
         month = 10;
        }
     else if (monthText == "Nov" || monthText == "November")
        {
         month = 11;
        }
     else if (monthText == "Dec" || monthText == "December")
        {
         month = 12;
        }
     
    // Exit Function
    return;
}
 
 bool isLeapYear(int year)
 {
    // Evaluate whether year is a leap year or not
     if (year%400 == 0)
        {
            return(true);
        }
    else if (year%4 == 0 && year%100 != 0)
        {
            return(true);
        }
    else
        {
            return(false);
        }   
 }
 
 int getCenturyValue(int year)
 {
    // Declare & Initialize Variables
     int f2=year/100;
     
    // Compute Century value
     f2 = f2%4;
     f2 = 3-f2; 
     
    // Exit Function
    return(f2*2);
}

 int getYearValue(int year)
 {
    // Declare & initialize variables
     int l2;
     l2 = year - (year/100*100); 
     
    // Compute year value and Exit Function
    return((l2) + (l2/4));
}

 int getMonthValue(int month, int year)
 {
     // Evaluate month and year to determine month value
     if (month ==1)
     {
         if (isLeapYear(year) == true)
         {
             return (6);
         }
         else
         {
             return (0);
         }
     }
     else if (month ==2)
     {
         if (isLeapYear(year) == true)
         {
             return (2);
         }
         else
         {
             return (3);
         }
     }
     else if (month ==3)
     {
         return (3);
     }
     else if (month == 4)
     {
         return (6);
     }
     else if (month == 5)
     {
         return (1);
     }
     else if (month == 6)
     {
         return (4);
     }
     else if (month ==7)
     {
         return (6);
     }
     else if (month == 8)
     {
         return (2);
     }
     else if (month == 9)
     {
         return (5);
     }
     else if (month == 10)
     {
         return (0);
     }
     else if (month == 11)
     {
         return (3);
     }
     else if (month == 12)
     {
         return (5);
     }
     else
     {
         return (666);
     }
}
 string dayOfWeek(int month, int day, int year)
{
     // Declare Variables
     int dow;
     
    // Calculate day of week integer
    dow = day + (getMonthValue(month, year) + getYearValue(year) + \
            getCenturyValue(year));
    dow = dow%7;
    
    // Translate day of week integer to corresponding string
    if (dow == 0)
    {
        return("Sunday");
    }
    else if (dow == 1)
    {
        return("Monday");
    }   
    else if (dow == 2)
    {
        return("Tuesday");
    }
    else if (dow == 3)
    {
        return("Wednesday");
    }
    else if (dow == 4)
    {
        return("Thursday");
    }
    else if (dow == 5)
    {
        return("Friday");
    }
    else if (dow == 6)
    {
        return("Saturday");
    }
    else
    {
        return ("Something went wrong");
    }
    
    // Exit Function
    return("fin");
}
