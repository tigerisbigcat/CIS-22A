/*****************************************************************************
  Filename:      Lab_4.cpp

  Author:        Lei Hao

  Date:          2019.07.25


Write a C++ program to aid the DeAnza Bookstore in estimating its business fornext quarter.
A New and Required book will sell to 90% (.90) of expected enrollment, but if it has been
used(Old) before and Required only 65% of the expected enrollment will buy it. Similarly,
40% of the expected enrollment will buy a newly(N) Suggested book, but only 20% will purchase
a Repeatedly(Old) Suggested book.

******************************************************************************/


#include <iostream>
#include <iomanip>
#include <string>
#include <locale>
#define PROFIT_RATE 0.20

using namespace std;

// decleared the variables.
string book_ISBN_number;


// declare functions.
int cal_book_needed(char text_req_sug, char text_new_old, double expected_class_enrollment);
double cal_profit(double price_per_copy, int est_book_needed);
void out_put(int est_book_needed, double est_book_sales);


// the main function.
int main() {
    
    double price_per_copy, expected_class_enrollment;
    char text_req_sug, text_new_old;
    
    // input the informations which need to show to users.
    cout << "Enter book number: ";
    cin >> book_ISBN_number;
    cout << "Enter price per copy: ";
    cin >> price_per_copy;
    cout << "Enter expected class enrollment: ";
    cin >> expected_class_enrollment;
    cout << "Enter 'R' if required or 'S' if suggested: ";
    cin >> text_req_sug;
    cout << "Enter 'N' if new or 'O' if not a new text: ";
    cin >> text_new_old;
    
    // case insensitive.
    text_req_sug = toupper(text_req_sug);
    text_new_old = toupper(text_new_old);
    
    // calculate the book we need;
    int est_book_needed = cal_book_needed(text_req_sug,text_new_old,expected_class_enrollment);
    
    // calculate the profit;
    double est_book_profit = cal_profit(price_per_copy, est_book_needed);
    
    //output
    out_put(est_book_needed, est_book_profit);
    
    cout << endl;
    
    return 0;
}


// cal_book_needed function
int cal_book_needed(char text_req_sug, char text_new_old, double expected_class_enrollment){
    
    const double new_required_factor = 0.9;
    const double old_required_factor = 0.65;
    const double new_suggest_factor = 0.4;
    const double old_suggest_factor = 0.2;
    double factor;
    
    if ( (text_req_sug == 'R') && (text_new_old == 'N') ){
        factor = new_required_factor;
    }
    
    else if ( (text_req_sug == 'R') && (text_new_old == 'O') ){
        factor = old_required_factor;
    }
    
    else if ( (text_req_sug == 'S') && (text_new_old == 'N') ){
        factor = new_suggest_factor;
    }
    
    else if ( (text_req_sug == 'S') && (text_new_old == 'O') ){
        factor = old_suggest_factor;
    }
    
    else{
        cout << "Error,please try again" << endl;
        exit(1);
        return 0;
    }
    
    int est_book_needed = static_cast<int>((factor * expected_class_enrollment) + 0.5);
    return est_book_needed;
}

// cal_book_profit function
double cal_profit(double price_per_copy, int est_book_needed) {
    double est_book_sales = est_book_needed * price_per_copy;
    double est_book_profit = est_book_sales * PROFIT_RATE;
    return est_book_profit;
}


// out_put function
void out_put(int est_book_needed, double est_book_profit) {
    cout << setprecision(2) << fixed;
    cout << "ISBN:" << book_ISBN_number << endl;
    cout << left << setw(14) << "Copies Needed:" << setw(1) << " " << setw(10) << est_book_needed << endl;
    cout << left << setw(8) << "Profit:" << setw(1) << "$" << setw(2) << " " << est_book_profit << endl;
}



/********************************** Result **************************
 Set 1 – 0755798652, 34.98, 31, R, O
 Enter book number: 0755798652
 Enter price per copy: 34.98
 Enter expected class enrollment: 31
 Enter 'R' if required or 'S' if suggested: R
 Enter 'N' if new or 'O' if not a new text: O
 ISBN:0755798652
 Copies Needed: 20
 Profit: $  139.92
 
 Program ended with exit code: 0
 
 
 Set 2 – 3453456784, 23.95, 100, r, N
 Enter book number: 3453456784
 Enter price per copy: 23.95
 Enter expected class enrollment: 100
 Enter 'R' if required or 'S' if suggested: r
 Enter 'N' if new or 'O' if not a new text: N
 ISBN:3453456784
 Copies Needed: 90
 Profit: $  431.10
 
 Program ended with exit code: 0
 
 
 Set 3 – 5677655673, 54.50, 40, R, O
 Enter book number: 5677655673
 Enter price per copy: 54.50
 Enter expected class enrollment: 40
 Enter 'R' if required or 'S' if suggested: R
 Enter 'N' if new or 'O' if not a new text: O
 ISBN:5677655673
 Copies Needed: 26
 Profit: $  283.40
 
 Program ended with exit code: 0
 
 
 Set 4 – 2462462464, 5.95, 40,s,O
 Enter book number: 2462462464
 Enter price per copy: 5.95
 Enter expected class enrollment: 40
 Enter 'R' if required or 'S' if suggested: s
 Enter 'N' if new or 'O' if not a new text: O
 ISBN:2462462464
 Copies Needed: 8
 Profit: $  9.52
 
 Program ended with exit code: 0
 
 
 Set 5 – 8953647888, 65.99, 35, N, Y
 Enter book number: 8953647888
 Enter price per copy: 65.99
 Enter expected class enrollment: 35
 Enter 'R' if required or 'S' if suggested: N
 Enter 'N' if new or 'O' if not a new text: Y
 Error,please try again
 Program ended with exit code: 1
 
 *******************************************************************/
