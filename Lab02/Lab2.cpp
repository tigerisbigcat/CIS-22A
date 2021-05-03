/*
 File name : lab_2.cpp
 Author  :  Lei Hao
 Date : July 16th 2019
 Description : What Taxation is all about.
 */

#include <iostream>
#include <iomanip> //Formatting functions
#define STATE_SALES_TAX_RATE 5.3   // "Preprocessor Directive macroa" to define constants
//setprecisio(), fixed
//setw()
//left, right
using namespace std;

int main()
{
    //Declare variables
    string month, year;
    double COUNTY_SALES_TAX_RATE = 3.1;
    double total_amount_collected, sales, county_sales_tax, state_sales_tax, total_sales_tax;

    //Input month, year, total amount collected
    cout << "Enter the collected month:" << endl;
    cin >> month;
    cout << "Enter the collected year:" << endl;
    cin >> year;
    cout << "Enter the total amount collected:" << endl;
    cin >> total_amount_collected;
    cout << endl << endl;
    
    //Compute Taxes and Sales
    sales  = total_amount_collected / (1 + COUNTY_SALES_TAX_RATE / 100 + STATE_SALES_TAX_RATE / 100);
    state_sales_tax = sales * STATE_SALES_TAX_RATE / 100;
    county_sales_tax = sales * COUNTY_SALES_TAX_RATE / 100;
    total_sales_tax = state_sales_tax + county_sales_tax;

    //Output
    cout << setprecision(2) << fixed;
    cout << "Month: " << month << ", " << year << endl;
    cout << setw(15) << setfill('-') << "" << endl; //
    cout << left << setw(25) << setfill(' ') << "Total Collected:" << setw(6) << "$" << total_amount_collected << endl;
    cout << left << setw(25) << "Sales:" << setw(6) << "$" << sales << endl;
    cout << left << setw(25) << "County Sales Tax:" << setw(6) << "$" << county_sales_tax << endl;
    cout << left << setw(25) << "State Sales Tax:" << setw(6) << "$" << state_sales_tax << endl;
    cout << left << setw(25) << "Total Sales Tax:" << setw(6) << "$" << total_sales_tax << endl;
   
    return 0;
}

/*
 Enter the collected month:
 March
 Enter the collected year:
 2019
 Enter the total amount collected:
 81673.67
 
 
 Month: March, 2019
 ---------------
 Total Collected:         $     81673.67
 Sales:                   $     75344.71
 County Sales Tax:        $     2335.69
 State Sales Tax:         $     3993.27
 Total Sales Tax:         $     6328.96
 Program ended with exit code: 0
 */
