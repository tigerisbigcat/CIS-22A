/*****************************************************************************
 Filename:      Lab5.cpp
 
 Author:        
 
 Date:          2019.07.30
 
 Write a C++ program to calculate the monthly cost of a house given the selling
 price, annual rate of interest, and number of years for the loan.
 
 ******************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cmath>

// macros to define the values.
#define TAX_RATE 0.0125
#define COST_OF_INSURANCE 550.00/12
#define COST_OF_UTILITIES 300.00

using namespace std;

// decleared the input function.
void input_info(double& sell_price, double& interest_rate, int& years_of_loan);
double cal_monthly_cost(double sell_price, double interest_rate, int years_of_loan, double& down_payment, double& loan_amount, double& monthly_mortgage_payment, double& mouthly_property_tax);
double down_payment(double sell_price);
double amount_of_loan(double sell_price, double down_payment);
double monthly_mortgage(double sell_price, double interest_rate, int years_of_loan, double loan_amount);
void output_data(double sell_price, double down_payment, double loan, double interest_rate, int years_of_loan, double property_tax, double mortgage);



/*****************************************************************************/
//
// Function:   main()
//
// Parameters: double& sell_price      - house price, in dollar
// (Inputs)    double& interest_rate   - interest rate, in percentage
//             double& down_payment    - for the house's down payment
//             double& loan_amount     - fot the house's loan from bank
//             double& monthly_mortgage_payment  - every month the mortgage amount, in dollar
//             double& mouthly_property_tax      - every month the property tax, in dollar
//             int years_of_loan       - for how long the loan last
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
//                  call "cal_monthly_cost" function
//                  call "output_data" function
//
/*****************************************************************************/
int main()
{

/*******************
//Variables:
********************/
    
    //define the variables.
    double sell_price, interest_rate, down_payment, loan_amount, monthly_mortgage_payment, mouthly_property_tax;
    int years_of_loan;

    
/*************************
//  Invoked Functions:
*************************/
    
    //"input_info" inputs mortgage data from user
    //a) house selling price
    //b) loan interest rate charged by the bank
    //c) number of years the user want to take to payoff the loan
    input_info(sell_price, interest_rate, years_of_loan);
    
    //"cal_monthly_costs" calculates the Monthly House Cost and gives:
    //a) down payment,
    //b) loan amount,
    //c) monthly mortgage payment,
    //d) monthly property tax payment,
    //e) monthly insurance premium payment, and
    //f) total monthly cost - sum of mortgage, utilities, tax and insurance
    cal_monthly_cost(sell_price, interest_rate, years_of_loan, down_payment, loan_amount, monthly_mortgage_payment, mouthly_property_tax);
    
    //"output_data" writes output data to lab5_output.txt file
    output_data(sell_price, down_payment, loan_amount, interest_rate, years_of_loan, mouthly_property_tax, monthly_mortgage_payment);
    
    return 0;
}


/*****************************************************************************/
//
// Function:   input_info( double& sell_price, double& interest_rate,
//                         int& years_of_loan)
//
// Parameters: double& sell_price     - house price, in dollar
// (Inputs)    double& INTEREST_RATE  - interest rate, in percentage
//             int& years_of_loan     - years of the loan, int number
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
// This function is provided the informations from users' input.
//
/*****************************************************************************/
void input_info(double& sell_price, double& interest_rate, int& years_of_loan)
{

    cout << "What's the selling price for the house? ";
    cin >> sell_price;
    cout << "What's the rate of interest? ";
    cin >> interest_rate;
    cout << "What's the number of years for the loan? ";
    cin >> years_of_loan;
    return;
}



/*****************************************************************************/
//
// Function:   double cal_monthly_cost(double& sell_price, double& interest_rate,
//                                    int& years_of_loan, double& down_payment,
//                                    double& loan_amount, double& monthly_mortgage_payment,
//                                    double& mouthly_property_tax)
//
// Parameters: double sell_price     - house price, in dollar
// (Inputs)    double interest_rate  - rate of interest per compounding period (annual rate/12)
//             int years_of_loan     - number of compounding periods (yrs*12)
//             double& d_payment     - for the house down  payment, in dollar
//             double& loan_amount   - for how much we have to get the loan from back, in dollar
//             double& monthly_mortgage_payment  - every month the mortgage amount, in dollar
//             double& mouthly_property_tax     - every month the property tax, in dollar
//
// Outputs:    None
//
// Returns:    double – mmonthly_mortgage_payment + COST_OF_UTILITIES + mouthly_property_tax + COST_OF_INSURANCE
//
// Author:     
//
// Date:       2019.7.30
//
// Description:
// This function call function - d_payment(sell_price)
//                             - amount_of_loan(sell_price)
//                             - monthly_mortgage(sell_price, interest_rate, years_of_loan)
// calculuate the value of "monthly_insurance" and "monthly_utilities"
// calculuate the sum of the monthly cost if you buy a house
//
/*****************************************************************************/
double cal_monthly_cost(double sell_price, double interest_rate, int years_of_loan, double& d_payment, double& loan_amount, double& monthly_mortgage_payment, double& mouthly_property_tax)
{
    d_payment = down_payment(sell_price);
    loan_amount = amount_of_loan(sell_price, d_payment);
    monthly_mortgage_payment = monthly_mortgage(sell_price, interest_rate, years_of_loan, loan_amount);
    mouthly_property_tax = sell_price * TAX_RATE / 12;
    
    //sum up all the monthly items, mortgage + utilities + property tax + insurance
    return monthly_mortgage_payment + COST_OF_UTILITIES + mouthly_property_tax + COST_OF_INSURANCE;
}



/*****************************************************************************/
//
// Function:   down_payment(double sell_price)
//
// Parameters: double sell_price     - house price, in dollar
// (Inputs)
//
// Outputs:    None
//
// Returns:    double – down payment
//
// Author:     
//
// Date:       2019.7.30
//
// Description:
// This function calculate the down payment of a house, by using this formula:
//               sell_price * DOWNPAYMENT_RATE
//
/*****************************************************************************/
double down_payment(double sell_price)
{
    const double DOWNPAYMENT_RATE = 0.2;
    return sell_price * DOWNPAYMENT_RATE;
}



/*****************************************************************************/
//
// Function:   amount_of_loan(double sell_price, double down_payment)
//
// Parameters: double sell_price     - house price, in dollar
// (Inputs)
//
// Outputs:    None
//
// Returns:    double – amount of the loan
//
// Author:     
//
// Date:       2019.7.30
//
// Description:
// This function calculate the amount of the loan, by using this formula:
//               sell_price * - do_payment
//
/*****************************************************************************/
double amount_of_loan(double sell_price, double down_payment)
{
    return sell_price - down_payment;
}



/*****************************************************************************/
//
// Function:   double monthly_mortgage(double sell_price, double interest_rate,
//                                     int years_of_loan, double loan_amount)
//
// Parameters: double sell_price     - house price, in dollar
// (Inputs)    double interest_rate  - rate of interest per compounding period (annual rate/12)
//             int years_of_loan     - number of compounding periods (yrs*12)
//             double loan_amount    - the amount of loan from bank.
//
// Outputs:    None
//
// Returns:    double – monthly mortgage
//
// Author:     
//
// Date:       2019.7.30
//
// Description:
// This function calculate the monthly mortgage, by using this formula:
//
//                      a * i * ( 1+i )^n
//         payment = ------------------------
//                      ( 1+i )^n - 1
//
//         where   a = amount of loan
//                 i = rate of interest per compounding period (annual rate/12)
//                 n = number of compounding periods (yrs*12)
//
/*****************************************************************************/
double monthly_mortgage(double sell_price, double interest_rate, int years_of_loan, double loan_amount)
{
    double monthly_interest_rate = interest_rate / 12;
    int num_of_loan = years_of_loan * 12;
    double calc_pow = pow((1 + monthly_interest_rate), num_of_loan);
    return (loan_amount * monthly_interest_rate * calc_pow) / (calc_pow - 1);
}



/*****************************************************************************/
//
// Function:   void output_data(double sell_price, double down_payment,
//                             double loan, double interest_rate, int years_of_loan,
//                             double property_tax, double mortgage)
//
// Parameters: double sell_price     - house price, in dollar
// (Inputs)    double& down_payment  - for the house down payment, in dollar
//             double& loan          - for how much we have to get the loan from back, in dollar
//             double interest_rate  - rate of interest per compounding period (annual rate/12)
//             int years_of_loan     - number of compounding periods (yrs*12)
//             double& property_tax      - every month the property tax, in dollar
//             double& mortgage_payment  - every month the mortgage amount, in dollar
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
// This function will give the format of all the output.
//
/*****************************************************************************/
void output_data(double sell_price, double down_payment, double loan, double interest_rate, int years_of_loan, double property_tax, double mortgage)
{
    ofstream file_out;
    string fill = " ";
    string fullname = "LeiHao_Lab5_output.txt";
    file_out.open(fullname.c_str());
    file_out << left << setw(60) << setfill('*') << "" << endl << endl;
    file_out << right << setw(39) << setfill(' ') << "MONTHLY COST OF HOUSE" << endl << endl;
    file_out << left << setw(60) << setfill('*') << "" << endl << endl;
    
    file_out << setw(1) << fill << setw(40) << left << setfill(' ') << "SELLING PRICE" << right << setw(2) << "$" << setw(13) << setprecision(2) << fixed << sell_price << endl;
    file_out << setw(1) << fill << setw(40) << left << "DOWN PAYMENT" << right << setw(2) << "$" << setw(13) << down_payment << endl;
    file_out << setw(1) << fill << setw(40) << left << "AMOUNT OF LOAN" << right << setw(2) << "$" << setw(13) << loan << endl << endl;
    
    file_out << setw(1) << fill << setw(26) << left << "INTEREST RATE" << setw(11) << right << interest_rate * 100.0 << setw(2) << "%" << endl;
    file_out << setw(1) << fill << setw(26) << left << "TAX RATE" << setw(11) << right << TAX_RATE * 100.0 << setw(2) << "%"<< endl << endl;
    
    file_out << setw(1) << fill << setw(26) << left << "DURATION OF LOAN (YEARS)" << setw(9) << right << years_of_loan << setw(4) << "yrs" << endl << endl << endl << endl << endl << endl;
    
    file_out << left << setw(18) << setfill('*') << "" << endl << endl;
    file_out << "MONTHLY PAYMENT" << endl << endl;
    file_out << left << setw(18) << setfill('*') << "" << endl << endl;
    
    file_out << setw(1) << fill << setw(40) << left << setfill(' ') << "MORTGAGE PAYMENT" << right << setw(2) << "$" << setw(13) << setprecision(2) << fixed << mortgage << endl;
    file_out << setw(1) << fill << setw(40) << left << "UTILITIES" << right << setw(2) << "$" << setw(13) << setprecision(2) << fixed << COST_OF_UTILITIES << endl;
    file_out << setw(1) << fill << setw(40) << left << "PROPERTY TAXES" << right << setw(2) << "$" << setw(13) << setprecision(2) << fixed << property_tax << endl;
    file_out << setw(1) << fill << setw(40) << left << "INSURANCE" << right << setw(2) << "$" << setw(13) << setprecision(2) << fixed << COST_OF_INSURANCE << endl;
    
    file_out << setw(1) << fill << left << setw(40) << setfill(' ') << " " << right << setw(15) << setfill('-') << "" << endl;
    file_out << setw(1) << fill << setw(40) << setfill(' ') << " " << right << setw(2) << "$" << setw(13) << setprecision(2) << fixed << (mortgage + COST_OF_UTILITIES + property_tax + COST_OF_INSURANCE) << endl;
    file_out.close();
}



/*****************************************************************************
 Output:
 
 Set 1 – $600,000, 5%, 20
 ************************************************************
 
 MONTHLY COST OF HOUSE
 
 ************************************************************
 
 SELLING PRICE                            $   1000000.00
 DOWN PAYMENT                             $    200000.00
 AMOUNT OF LOAN                           $    800000.00
 
 INTEREST RATE                    0.33 %
 TAX RATE                         1.25 %
 
 DURATION OF LOAN (YEARS)         30 yrs
 
 
 
 
 
 ******************
 
 MONTHLY PAYMENT
 
 ******************
 
 MORTGAGE PAYMENT                         $      3819.32
 UTILITIES                                $       300.00
 PROPERTY TAXES                           $      1041.67
 INSURANCE                                $        45.83
                                         ---------------
                                          $      5206.82
 
 
 
 
 
 
 Set 2 – $400,000, 4.2%, 30
 ************************************************************
 
 MONTHLY COST OF HOUSE
 
 ************************************************************
 
 SELLING PRICE                            $    400000.00
 DOWN PAYMENT                             $     80000.00
 AMOUNT OF LOAN                           $    320000.00
 
 INTEREST RATE                    4.20 %
 TAX RATE                         1.25 %
 
 DURATION OF LOAN (YEARS)         30 yrs
 
 
 
 
 
 ******************
 
 MONTHLY PAYMENT
 
 ******************
 
 MORTGAGE PAYMENT                         $      1564.85
 UTILITIES                                $       300.00
 PROPERTY TAXES                           $       416.67
 INSURANCE                                $        45.83
                                         ---------------
                                          $      2327.35

 
 ******************************************************************************/
