/*****************************************************************************
 Filename:      LeiHao_Lab6.cpp
 
 Author:        
 
 Date:          2019.08.05
 
 Write a C++ program to output the monthly payment schedule for a credit card
 debt, when each month nothing more is charged to the account but only the
 minimum payment is paid. The output stops when the balance is fully paid -
 remaining balance = 0.

 *******************
 Input:
 *******************
 
 Data input must be done in a separate function.
 Input the following: credit card balance, interest rate on your credit card
 and percent of minimum payment. Test data: 624, 24, 4
 
 Data must be read from a file called lab6.txt, which you must create first
 and format it the way you see fit to store the test  data listed above.
 
 
 *******************
 Calculate:
 *******************
 
 A loop can be configured in main() to periodically calculate and output monthly
 data. This (calculate)function must be called from main() and within the loop.
 
 For each month, calculate the amount of interest to be paid that month (adding
 this into balance before calculating minimum payment), total of interest paid,
 amount of minimum payment due for the month. And, lastly, update new balance.
 
 If the calculated minimum payment is less than $15.00, then reset it at $15.00
 - a practical threshold. Otherwise, the calculated value will become impractically
 smaller and smaller for many payment periods.
 
 And, lastly, the final payment would be the remaining sum owed, final balance,
 its value would be less than $15.00.
 
 
 *******************
 Output:
 *******************
 
 This function must be called from main(), from within the loop.
 
 There needs to be a separate function, to output the table heading, including
 data read from the input data file; see sample below.
 
 For each period, the data output function should output month(count), balance
 at the end of the month, interest paid that month, minimum payment for that
 month, and the sum of amount of interest paid so far(accumulated).
 
 All outputs must be redirected to a file.
 
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <iomanip>


using namespace std;

// define the functions. prototype.
void input_info(double& credit_card_balance, double& interest_rate, double& percent_of_min_payment);
double calc_monthly_payment(double& credit_card_balance, double interest_rate, double percent_of_min_payment, double& min_payment, double& interest_this_month, double& sum_interest);
void output_header(double credit_card_balance, double interest_rate, double percent_of_min_payment);
void output_monthly_data(double credit_card_balance, double min_payment, double interest_this_month, double sum_interest, int month);



/*****************************************************************************/
//
// Function:   main()
//
// Parameters: double credit_card_balance      - current credit card balance
// (Inputs)    double interest_rate            - interest rate, in percentage
//             double percent_of_min_payment   - minimum percentage of payment every month
//             double min_payment              - minimum amount of payment every month
//             double interest_this_month      - amount of interest for this month
//             double sum_interest             - sum of the interest paid
//             int month                       - for how long have to pay off
//
// Outputs:    None
//
// Returns:    0
//
// Author:     
//
// Date:       2019.7.30
//
// Description:
// This function is call "input_info" function
//                  call "output_header" function
//                  a loop for calculation
//                  in the loop, we call "calc_monthly_payment"
//                  and "output_monthly_data" function
//
/*****************************************************************************/
int main() {
    
/*******************
//Variables:
********************/
    
    // define the variables.
    double credit_card_balance, interest_rate, percent_of_min_payment, min_payment, interest_this_month, sum_interest;
    int month;
    
    
/*************************
//  Invoked Functions:
*************************/
    
    // input function read the data from the "lab6.txt" file.
    input_info(credit_card_balance, interest_rate, percent_of_min_payment);
    
    // output the header to the "LeiHao_Lab6_output.txt"
    output_header(credit_card_balance, interest_rate, percent_of_min_payment);
    
    // this loop culcalate the whole row data. in the loop call two functions.
    for (month = 1; credit_card_balance > 0; month++)
    {
        // call the calca_monthly_payment function to calculate.
        calc_monthly_payment(credit_card_balance, interest_rate, percent_of_min_payment, min_payment, interest_this_month, sum_interest);
        // output the whole row's data to the file.
        output_monthly_data(credit_card_balance, min_payment, interest_this_month, sum_interest, month);
    }
    
    return 0;
}



/*****************************************************************************/
//
// Function:   input_info()
//
// Parameters: double& credit_card_balance       - current credit card balance
// (Inputs)    double& interest_rate             - interest rate, in percentage
//             double& percent_of_min_payment)   - minimum percentage of payment every month
//
// Outputs:    None
//
// Returns:    None
//
// Author:     
//
// Date:       2019.7.30
//
// Description:
// This function is read the data from "lab6.txt" file
//                  check if the file exists
//                  hold the data in the variable
//                  close the file
//
/*****************************************************************************/
void input_info(double& credit_card_balance, double& interest_rate, double& percent_of_min_payment)
{
    ifstream file_in; //declare a reference to file
    file_in.open("lab6.txt");

    if (file_in.fail()) //check file if exists
    {
        cout << "No such file" << endl;
        exit(100);
    }
    
    // hold the value in the variables
    file_in >> credit_card_balance >> interest_rate >> percent_of_min_payment;
    file_in.close();

}


/*****************************************************************************/
//
// Function:   calc_monthly_payment()
//
// Parameters: double& credit_card_balance      - current credit card balance
// (Inputs)    double interest_rate             - interest rate, in percentage
//             double percent_of_min_payment    - minimum percentage of payment every month
//             double& min_payment              - minimum amount of payment every month
//             double& interest_this_month      - amount of interest for this month
//             double& sum_interest             - sum of the interest paid
//
// Outputs:    None
//
// Returns:    None
//
// Author:     
//
// Date:       2019.7.30
//
// Description:
// This function is calculate the one row data
//
/*****************************************************************************/
double calc_monthly_payment(double& credit_card_balance, double interest_rate, double percent_of_min_payment, double& min_payment, double& interest_this_month, double& sum_interest)
{
    // % format
    percent_of_min_payment /= 100;
    interest_rate /= 1200;
    const double min_amount = 15.00;
    
    // formula
    interest_this_month = credit_card_balance * interest_rate;
    min_payment = (credit_card_balance + interest_this_month) * percent_of_min_payment;
    sum_interest += interest_this_month;

    // condition check
    if (min_payment < min_amount)
    {
        if (credit_card_balance > min_amount)
        {
            min_payment = min_amount;
        }
        
        else if (credit_card_balance < min_amount)
        {
            min_payment = credit_card_balance * (1 + interest_rate);
        }
    }
    
    // calculate the credit card balance
    credit_card_balance = (credit_card_balance * (1 + interest_rate) - min_payment);
    return credit_card_balance;
}



/*****************************************************************************/
//
// Function:   output_header()
//
// Parameters: double credit_card_balance       - current credit card balance
// (Inputs)    double interest_rate             - interest rate, in percentage
//             double percent_of_min_payment)   - minimum percentage of payment every month
//
// Outputs:    None
//
// Returns:    None
//
// Author:     
//
// Date:       2019.7.30
//
// Description:
// This function is output the header to the "LeiHao_Lab6_output.txt" file
//
/*****************************************************************************/
void output_header(double credit_card_balance, double interest_rate, double percent_of_min_payment)
{
    ofstream file_out;
    string fill = " ";
    string fullname = "LeiHao_Lab6_output.txt";
    std::ofstream outfile;

    // creat a file
    file_out.open(fullname.c_str());
    
    //check file if exists
    if (file_out.fail())
    {
        cout << "No such file" << endl;
        exit(100);
    }

    // write the data to the file
    file_out << left << setw(10) << fill << setw(15) << "Balance Owing:" << right << setw(2) << "$" << setw(8) << setprecision(2) << fixed << credit_card_balance << endl;
    file_out << left << setw(10) << fill << setw(8) << "APR as % " << setprecision(0) << fixed << interest_rate << endl;
    file_out << left << setw(10) << fill << setw(20) << "Percent for minimum payment as %" << percent_of_min_payment << endl << endl;
    file_out << left << setw(7) << fill << setw(38) << setfill('-') << "" << endl << endl;
    file_out << setfill(' ') << "" << right << setw(8) << "Month" << setw(10) << "Balance" << setw(23) << "Interest this month" << setw(12) << "Minimum" << setw(24) << "Sum of interest paid" << endl;
    
}


/*****************************************************************************/
//
// Function:   output_monthly_data()
//
// Parameters: double credit_card_balance       - current credit card balance
// (Inputs)    double interest_rate             - interest rate, in percentage
//             double percent_of_min_payment)   - minimum percentage of payment every month
//             double sum_interest              - sum of the interest paid
//             int month                        - for how long have to pay off
//
// Outputs:    None
//
// Returns:    None
//
// Author:     
//
// Date:       2019.7.30
//
// Description:
// This function is output the monthly data
//                  use std::ofstream::app to put the row data into "LeiHao_Lab6_output.txt" file
//
/*****************************************************************************/
void output_monthly_data(double credit_card_balance, double min_payment, double interest_this_month, double sum_interest, int month)
{
    ofstream file_out;
    string fill = " ";
    string fullname = "LeiHao_Lab6_output.txt";
    file_out.open(fullname.c_str(), std::ofstream::app);
    
    //check file if exists
    if (file_out.fail())
    {
        cout << "No such file" << endl;
        exit(100);
    }
    
    // write the data to the file
    file_out << right << setw(8) << month << setw(10) << setprecision(2) << fixed << credit_card_balance << setw(23) << interest_this_month << setw(12) << min_payment << setw(24) << sum_interest << endl;
    file_out.close();
}




/*****************************************************************************
 Output:
 
 
            Balance Owing:  $  624.00
            APR as % 24
            Percent for minimum payment as %4
 
         --------------------------------------
 
 Month   Balance    Interest this month     MinimumSum of interest paid
  1       611.02                  12.48       25.46             12.48
  2       598.31                  12.22       24.93             24.70
  3       585.87                  11.97       24.41             36.67
  4       573.68                  11.72       23.90             48.38
  5       561.75                  11.47       23.41             59.86
  6       550.06                  11.23       22.92             71.09
  7       538.62                  11.00       22.44             82.09
  8       527.42                  10.77       21.98             92.87
  9       516.45                  10.55       21.52            103.41
 10       505.71                  10.33       21.07            113.74
 11       495.19                  10.11       20.63            123.86
 12       484.89                   9.90       20.20            133.76
 13       474.80                   9.70       19.78            143.46
 14       464.93                   9.50       19.37            152.96
 15       455.26                   9.30       18.97            162.25
 16       445.79                   9.11       18.57            171.36
 17       436.51                   8.92       18.19            180.27
 18       427.43                   8.73       17.81            189.01
 19       418.54                   8.55       17.44            197.55
 20       409.84                   8.37       17.08            205.92
 21       401.31                   8.20       16.72            214.12
 22       392.97                   8.03       16.37            222.15
 23       384.79                   7.86       16.03            230.01
 24       376.79                   7.70       15.70            237.70
 25       368.95                   7.54       15.37            245.24
 26       361.28                   7.38       15.05            252.62
 27       353.50                   7.23       15.00            259.84
 28       345.57                   7.07       15.00            266.91
 29       337.48                   6.91       15.00            273.82
 30       329.23                   6.75       15.00            280.57
 31       320.82                   6.58       15.00            287.16
 32       312.24                   6.42       15.00            293.58
 33       303.48                   6.24       15.00            299.82
 34       294.55                   6.07       15.00            305.89
 35       285.44                   5.89       15.00            311.78
 36       276.15                   5.71       15.00            317.49
 37       266.67                   5.52       15.00            323.01
 38       257.01                   5.33       15.00            328.35
 39       247.15                   5.14       15.00            333.49
 40       237.09                   4.94       15.00            338.43
 41       226.83                   4.74       15.00            343.17
 42       216.37                   4.54       15.00            347.71
 43       205.69                   4.33       15.00            352.03
 44       194.81                   4.11       15.00            356.15
 45       183.70                   3.90       15.00            360.04
 46       172.38                   3.67       15.00            363.72
 47       160.83                   3.45       15.00            367.17
 48       149.04                   3.22       15.00            370.38
 49       137.02                   2.98       15.00            373.36
 50       124.76                   2.74       15.00            376.10
 51       112.26                   2.50       15.00            378.60
 52        99.51                   2.25       15.00            380.84
 53        86.50                   1.99       15.00            382.84
 54        73.23                   1.73       15.00            384.56
 55        59.69                   1.46       15.00            386.03
 56        45.88                   1.19       15.00            387.22
 57        31.80                   0.92       15.00            388.14
 58        17.44                   0.64       15.00            388.78
 59         2.79                   0.35       15.00            389.13
 60         0.00                   0.06        2.84            389.18
*****************************************************************************/
