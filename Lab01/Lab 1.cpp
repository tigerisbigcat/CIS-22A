/*
 File name : lab_1.cpp
 Author  :  Lei Hao
 Date : July 12th 2019
*/

#include <iostream>
using namespace std;

int main()
{
    cout << "Solution provided by Lei Hao." << endl << endl;
    
    //creates integer for coins input
    int quarters, dimes, nickels, pennies;
    cout << "Please enter the number of quarters: ";
    
    //for coin input
    cin >> quarters;
    cout << "Please enter the number of dines: ";
    cin >> dimes;
    cout << "Please enter the number of nickels: ";
    cin >> nickels;
    cout << "Please enter the number of pennies: ";
    cin >> pennies;
    cout << "Thank you." << endl << endl;
    
    //calculate the total.
    double total = quarters/4.0 + dimes/10.0 + nickels/20.0 + pennies/100.0;
    
    //output the sentence.
    cout << "The total value of " << quarters << " quarters, " << dimes << " dimes, "
    << nickels << " nickels and " << pennies << " pennies is $" << total << "." << endl;
}

/*
 Solution provided by Lei Hao.

 Please enter the number of quarters: 3
 Please enter the number of dines: 0
 Please enter the number of nickels: 5
 Please enter the number of pennies: 23
 Thank you.
 
 The total value of 3 quarters, 0 dimes, 5 nickels and 23 pennies is $1.23.
 Program ended with exit code: 0
 */
