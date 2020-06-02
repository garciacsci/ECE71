/* Homework 23*/

/* 
 * File:    hw23.cpp
 * Author:  Christopher Garcia
 * Purpose: Calculate various statistical properties of an array of numbers, 
 *          including the maximum, minimum, average, variance, 
 *          standard deviation, standard error, and median. 
 * Date:    March 26, 2020
 */

// Preprocessor Directives
#include <cstdlib> 
#include <cmath> 
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Declare constants
const int MAX_SIZE=100;

// Function Prototypes
double maximum(const double a[], int n);
// Precondition:    n declared as the size of the array
//                  a[0] - a[n-1] have values
// Returns the max

//------------------------------------------------------------------------------

double minimum(const double a[], int n);
// Precondition:    n declared as the size of the array
//                  a[0] - a[n-1] have values
// Returns the min 

//------------------------------------------------------------------------------

double average(const double a[], int n);
// Precondition:    n declared as the size of the array
//                  a[0] - a[n-1] have values
// Returns the average


//------------------------------------------------------------------------------

double variance(const double a[], int n);
// Precondition:    n declared as the size of the array
//                  a[0] - a[n-1] have values
// Returns the variance

//------------------------------------------------------------------------------

double stdDev(const double a[], int n);
// Precondition:    n declared as the size of the array
//                  a[0] - a[n-1] have values
// returns the standard deviation

//------------------------------------------------------------------------------

double stdErr(const double a[], int n);
// Precondition:    n declared as the size of the array
//                  a[0] - a[n-1] have values
// Returns the standard error

//------------------------------------------------------------------------------

double median(double a[], int n);
// Precondition:    n declared as the size of the array
//                  a[0] - a[n-1] have values
// Returns the median

//------------------------------------------------------------------------------

void sort(double a[], int numberUsed);
//Precondition: numberUsed <= declared size of the array a.
//The array elements a[0] through a[numberUsed - 1] have values.
//Postcondition: The values of a[0] through a[numberUsed - 1] have
//been rearranged so that a[0] <= a[1] <= ... <= a[numberUsed - 1].

//------------------------------------------------------------------------------

void swapValues(int &v1, int &v2, double a[], int n);
//Interchanges the values of v1 and v2.

//------------------------------------------------------------------------------

int indexOfSmallest(const double a[], int startIndex, int numberUsed);
//Precondition: 0 <= startIndex < numberUsed. Referenced array elements have
//values.
//Returns the index i such that a[i] is the smallest of the values
//a[startIndex], a[startIndex + 1], ..., a[numberUsed - 1].

//------------------------------------------------------------------------------

int main(int argc, char** argv) 
{
    // Declare Variables
    int n;
    double a[MAX_SIZE];
    
    // Greet the user
    cout << "Welcome to the Statistical Functions Program" << endl;
    
    // Prompt user for number of values to be entered and make sure maximum
    // size is not exceeded
    do
    {
    cout << "Number of values to be entered: ";
    cin >> n;
    cout << endl;
    
    if (n>MAX_SIZE)
        cout << "Only up to 100 values can be entered." << endl;
    } while (n>MAX_SIZE);
    
    // Prompt for and read elements into array 
    for (int i=0; i<n; i++)
    {
        cout << "Enter number " << (i+1) << ": ";
        cin >> a[i];
    }
    
    // Set formatting
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    // Print statistics
    cout << endl;    
    cout << "The maximum is: " << maximum(a,n) << endl;
    cout << "The minimum is: " << minimum(a,n) << endl;
    cout << "The average is: " << average(a,n) << endl;
    cout << "The variance is: " << variance(a,n) << endl;
    cout << "The standard deviation is: " << stdDev(a,n) << endl;
    cout << "The standard error is: " << stdErr(a,n) << endl;
    cout << "The median is: " << median(a,n);
    
    // Exit Program
    exit(EXIT_SUCCESS);
}

//------------------------------------------------------------------------------

// Function Definitions
double maximum(const double a[], int n)
{
    // Declare Variables
    double max=a[n - (n-1)];
    
    // Find the max
    for (int i=1; i<n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    
    // Return the max
    return(max);
    
}

//------------------------------------------------------------------------------

double minimum(const double a[], int n)
{
    // Declare Variables
    double min=a[0];
        
    // Find the Minimum
    for (int i=1; i<n; i++)
    {
        if (a[i] < min)
            min = a[i];
    }
    
    // Return the minimum
    return(min);
}

//------------------------------------------------------------------------------

double average(const double a[], int n)
{
    // Declare Variables
    double total=0;
    
    // Find the total of the values stored in the array
    for (int i=0; i<n; i++)
    {
        total += a[i];
    }
    
    // calculate and return the average
    return(total/n);
}

//------------------------------------------------------------------------------

double variance(const double a[], int n)
{
    // Declare variables
    double sum=0;
    
    // Calculate the sum of the squares of the differences of the elements
    // of the array and the average of the array
    for (int i=0; i<n; i++)
    {
        sum += pow((a[i] - average(a,n)),2);
    }
    
    // calculate and return the variance
    return (sum/n);
}

//------------------------------------------------------------------------------

double stdDev(const double a[], int n)
{    
    // Calculate and return the standard deviation
    return (sqrt(variance(a,n)));
}

//------------------------------------------------------------------------------

double stdErr(const double a[], int n)
{
    // Calculate and return the standard error
    return (stdDev(a,n)/sqrt(n));
}

//------------------------------------------------------------------------------


double median(double a[], int n)
{
    // Declare variables
    double med,left, right;
    
    // Sort the array
    sort(a,n);
    
    // Find the median
    // Check if odd or even number of elements
    if ((n%2) == 0)
    {
        left = a[n/2];
        right = a[((n/2) - 1)];
        med = ((left + right)/2);        
    }
    else
    {
        med = a[(n/2)];
    }
    
    // Return the median
    return (med);
}

//------------------------------------------------------------------------------


void sort(double a[], int numberUsed)
{
    // Declare Variables
    int indexOfNextSmallest;

    for (int index = 0; index < numberUsed - 1; index++)
    {//Place the correct value in a[index]:
        indexOfNextSmallest =
                     indexOfSmallest(a, index, numberUsed);
        swapValues(index, indexOfNextSmallest, a, numberUsed);
        //a[0] <= a[1] <=...<= a[index] are the smallest of the original array
        //elements. The rest of the elements are in the remaining positions.
    }
}

//------------------------------------------------------------------------------


void swapValues(int &v1, int &v2, double a[], int n)
{
    // Declare Variables
    double temp;
    
    // Swap the elements of the two specified array addresses
    temp = a[v1];
    a[v1] = a[v2];
    a[v2] = temp;
}

//------------------------------------------------------------------------------


int indexOfSmallest(const double a[], int startIndex, int numberUsed)
{
    // Declare and initialize variables
    int min = a[startIndex],
        indexOfMin = startIndex;
    
    // Find the index of the minimum
    for (int index = startIndex + 1; index < numberUsed; index++)
        if (a[index] < min)
        {
            min = a[index];
            indexOfMin = index;
            //min is the smallest of a[startIndex] through a[index]
        }

    // Return the index of the minimum
    return (indexOfMin);
}
