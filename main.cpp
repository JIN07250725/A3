// ------------- FILE HEADER -------------
// Author: Yusong Jin
// Assignment: 3
// Date: July 8
// Description: Ferries
// Sources: 

// ------------- ZYBOOKS SCORES -------------
// https://learn.zybooks.com/zybook/PCCCS161ASummer25
// Chapter: 3
// Participation: 100%
// Challenge: 100%
// Labs: 100%

// ------------- DISCORD POSTS -------------
// https://discord.com/invite/URYKKf8YHm
// Count: 2
// Links (Optional): 

// ------------- DESIGN DOCUMENT -------------
// A. INPUT [yes/no]: yes
// B. OUTPUT [yes/no]: yes
// C. CALCULATIONS [yes/no]: yes
// D. LOGIC and ALGORITHMS [yes/no]: yes
//    (Optional) flow chart link or file name: 

// ------------- TESTING -------------
// PASS ALL GIVEN SAMPLE RUN TESTS [yes/no]: yes
// (Optional) Additional tests count:   

// ------------- CODE -------------
#include <iostream>
#include <iomanip>
using namespace std;

// Function to validate input (non-negative)
bool validateInput(int value) {
    return (value >= 0);
}

void displayGroupSizeErrorAndExit() {
    cout << "\nUh oh!! Too many people in your group. Split into 2 groups and try again!\n\n";
    cout << "Thank you for using Washington State Ferries Fare Calculator!\n";
    exit(0);
}

void displayInputErrorAndExit() {
    cout << "\nError!! Invalid answer!! Please try again later!!!\n\n";
    cout << "Thank you for using Washington State Ferries Fare Calculator!\n";
    exit(0);
}

int main() {
    // Display welcome message and fare table
    cout << "Welcome to the Washington State Ferries Fare Calculator!\n\n";
    
    cout << "Fare Description                                           Ticket $\n";
    cout << "--------------------------------------                     --------\n";
    cout << "Vehicle Under 14' (less than 168\") & Driver                 $57.90\n";
    cout << "Adult (age 19 - 64)                                         $14.95\n";
    cout << "Senior (age 65 & over) / Disability                         $7.40\n";
    cout << "Youth (age 6 - 18)                                          $5.55\n";
    cout << "Bicycle Surcharge (included with Vehicle)                   $4.00\n\n";
    
    // Vehicle question
    char vehicleResponse;
    cout << "Are you riding a vehicle on the Ferry (Y/N): ";
    cin >> vehicleResponse;
    
    // Validate vehicle response
    vehicleResponse = toupper(vehicleResponse);
    if (vehicleResponse != 'Y' && vehicleResponse != 'N') {
        displayInputErrorAndExit();
    }
    
    int adults, seniors, youths, bikes = 0;
    double totalFare = 0.0;
    
    if (vehicleResponse == 'Y') {
        // Vehicle scenario
        totalFare = 57.90; // Base vehicle fee
        
        cout << "\nHow many adults? ";
        cin >> adults;
        if (!validateInput(adults)) displayInputErrorAndExit();
        
        cout << "How many seniors? ";
        cin >> seniors;
        if (!validateInput(seniors)) displayInputErrorAndExit();
        
        cout << "How many youths? ";
        cin >> youths;
        if (!validateInput(youths)) displayInputErrorAndExit();
        
        // Validate group size (driver not counted)
        if ((adults + seniors + youths) > 20) {
            displayGroupSizeErrorAndExit();
        }
        
        totalFare += adults * 14.95 + seniors * 7.40 + youths * 5.55;
    } 
    else {
        // No vehicle scenario
        cout << "\nHow many adults? ";
        cin >> adults;
        if (!validateInput(adults)) displayInputErrorAndExit();
        
        cout << "How many seniors? ";
        cin >> seniors;
        if (!validateInput(seniors)) displayInputErrorAndExit();
        
        cout << "How many youths? ";
        cin >> youths;
        if (!validateInput(youths)) displayInputErrorAndExit();
        
        cout << "How many bikes? ";
        cin >> bikes;
        if (!validateInput(bikes)) displayInputErrorAndExit();
        
        // Validate passenger count
        if ((adults + seniors + youths) > 20) {
            displayGroupSizeErrorAndExit();
        }
        
        totalFare += adults * 14.95 + seniors * 7.40 + youths * 5.55 + bikes * 4.00;
    }
    
    // Display results
    cout << fixed << setprecision(2);
    cout << "\nYour total charge is $" << totalFare << "\n\n";
    
    // Check for free ticket eligibility
    if (totalFare > 100.00) {
        cout << "You get a free adult ticket for your next trip.\n\n";
    } 
    else {
        double difference = 100.00 - totalFare;
        cout << "If you spend $" << difference << " more, you are eligible for a free adult ticket for the next trip.\n\n";
    }
    
    // Closing message
    cout << "Thank you for using Washington State Ferries Fare Calculator!\n";
    return 0;
}





// ------------- DESIGN -------------
/* 
Program Name: Washington State Ferries

Program Description: Ferry Fare Calculator

Design:

A. INPUT
Define the input variables including name data type. 
char vehicleResponse;      // User input: 'Y'/'N' for vehicle
int adults;                // Number of adult passengers (19-64)
int seniors;               // Number of senior passengers (65+ or disabled)
int youths;                // Number of youth passengers (6-18)
int bikes;                 // Number of bicycles (only if no vehicle)

B. OUTPUT
double totalFare;         // Total calculated fare ($XX.XX format, 2 decimal precision)
double difference;        // Amount needed to reach $100 (if totalFare < 100)

C. CALCULATIONS
Describe calculations used by algorithms in step D.  
List all formulas. 

With Vehicle:
totalFare = 57.90 + (adults * 14.95) + (seniors * 7.40) + (youths * 5.55)

Without Vehicle:
totalFare = (adults * 14.95) + (seniors * 7.40) + (youths * 5.55) + (bikes * 4.00)

Free Ticket Check:
if (totalFare > 100.00) -> " Get a free adult ticket for next trip"
else -> difference = 100.00 - totalFare

D. LOGIC and ALGORITHMS
Design the logic of your program using pseudocode or flowcharts. 
Use conditionals, loops, functions or array constructs.
List the steps in transforming inputs into outputs. 

BEGIN
    PRINT welcome message
    PRINT fare information table with proper formatting
    
    PROMPT "Are you riding a vehicle on the Ferry (Y/N): "
    READ vehicle_answer
    
    CONVERT vehicle_answer to uppercase
    
    IF vehicle_answer is not 'Y' or 'N' THEN
        PRINT error message
        PRINT goodbye message
        EXIT program
    END IF
    
    IF vehicle_answer is 'Y' THEN
        SET total = 57.90  // Vehicle and driver fee
        
        PROMPT "How many adults? "
        READ adults
        PROMPT "How many seniors? "
        READ seniors
        PROMPT "How many youths? "
        READ youths
        
        IF any input is negative OR total passengers > 20 THEN
            PRINT error message
            PRINT goodbye message
            EXIT program
        END IF
        
        CALCULATE total += adults * 14.95
        CALCULATE total += seniors * 7.40
        CALCULATE total += youths * 5.55
    ELSE
        SET total = 0.0
        
        PROMPT "How many adults? "
        READ adults
        PROMPT "How many seniors? "
        READ seniors
        PROMPT "How many youths? "
        READ youths
        PROMPT "How many bikes? "
        READ bikes
        
        IF any input is negative OR total passengers > 20 THEN
            PRINT error message
            PRINT goodbye message
            EXIT program
        END IF
        
        CALCULATE total += adults * 14.95
        CALCULATE total += seniors * 7.40
        CALCULATE total += youths * 5.55
        CALCULATE total += bikes * 4.00
    END IF
    
    PRINT "Your total charge is $", total formatted to 2 decimal places
    
    IF total > 100.00 THEN
        PRINT "You get a free adult ticket for your next trip."
    ELSE
        CALCULATE difference = 100.00 - total
        PRINT "If you spend $", difference, " more, you are eligible for a free adult ticket for the next trip."
    END IF
    
    PRINT goodbye message
END

SAMPLE RUNS
Copy from assignment document.

Welcome to the Washington State Ferries Fare Calculator!

Fare Description                                           Ticket $
--------------------------------------                     --------
Vehicle Under 14' (less than 168") & Driver                 $57.90
Adult (age 19 - 64)                                         $14.95
Senior (age 65 & over) / Disability                         $7.40
Youth (age 6 - 18)                                          $5.55
Bicycle Surcharge (included with Vehicle)                   $4.00

Are you riding a vehicle on the Ferry (Y/N): y

How many adults? 2
How many seniors? 1
How many youths? 0

Your total charge is $95.20

If you spend $4.80 more, you are eligible for a free adult ticket for the next trip.

Thank you for using Washington State Ferries Fare Calculator!
Welcome to the Washington State Ferries Fare Calculator!

Fare Description                                           Ticket $
--------------------------------------                     --------
Vehicle Under 14' (less than 168") & Driver                 $57.90
Adult (age 19 - 64)                                         $14.95
Senior (age 65 & over) / Disability                         $7.40
Youth (age 6 - 18)                                          $5.55
Bicycle Surcharge (included with Vehicle)                   $4.00

Are you riding a vehicle on the Ferry (Y/N): a

Error!! Invalid answer!! Please try again later!!!

Thank you for using Washington State Ferries Fare Calculator!
Welcome to the Washington State Ferries Fare Calculator!

Fare Description                                           Ticket $
--------------------------------------                     --------
Vehicle Under 14' (less than 168") & Driver                 $57.90
Adult (age 19 - 64)                                         $14.95
Senior (age 65 & over) / Disability                         $7.40
Youth (age 6 - 18)                                          $5.55
Bicycle Surcharge (included with Vehicle)                   $4.00

Are you riding a vehicle on the Ferry (Y/N): n

How many adults? 2
How many seniors? 1
How many youths? 1
How many bikes? 2

Your total charge is $50.85

If you spend $49.15 more, you are eligible for a free adult ticket for the next trip.

Thank you for using Washington State Ferries Fare Calculator!
Welcome to the Washington State Ferries Fare Calculator!

Fare Description                                           Ticket $
--------------------------------------                     --------
Vehicle Under 14' (less than 168") & Driver                 $57.90
Adult (age 19 - 64)                                         $14.95
Senior (age 65 & over) / Disability                         $7.40
Youth (age 6 - 18)                                          $5.55
Bicycle Surcharge (included with Vehicle)                   $4.00

Are you riding a vehicle on the Ferry (Y/N): n
How many adults? -7

Error!! Invalid answer!! Please try again later!!!

Thank you for using Washington State Ferries Fare Calculator!
Welcome to the Washington State Ferries Fare Calculator!

Fare Description                                           Ticket $
--------------------------------------                     --------
Vehicle Under 14' (less than 168") & Driver                 $57.90
Adult (age 19 - 64)                                         $14.95
Senior (age 65 & over) / Disability                         $7.40
Youth (age 6 - 18)                                          $5.55
Bicycle Surcharge (included with Vehicle)                   $4.00

Are you riding a vehicle on the Ferry (Y/N): n

How many adults? 12
How many seniors? 4
How many youths? 5
How many bikes? 2

Uh oh!! Too many people in your group. Split into 2 groups and try again!

Thank you for using Washington State Ferries Fare Calculator!

*/