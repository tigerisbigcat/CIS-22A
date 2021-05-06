/*****************************************************************************/
//  Filename:      Lab_3.cpp
//
//  Author:        Lei Hao
//
//  Date:          2009.07.20
//
//
//  Description: Create a customer bill for a company. The company sells only five products: TV, DVD player, Remote
//  Controller, CD Player, and Audio Visual Processor. The unit prices are $500.00, $380.00, $35.20, $74.50, and
//  $1500.00, respectively.
//
/*****************************************************************************/

#include <iostream>
#include <iomanip>
#define TAX_RATE 0.0875

using namespace std;

int main()
{
    //Declare variables
    double TV_PRICE = 500.00, DVD_PRICE = 380.00, REMOTE_CONTROLLER_PRICE = 35.20, CD_PLAYER_PRICE = 74.50, AV_PROCESSOR_PRICE = 1500.00;
    int tv_sold_amount, dvd_sold_amount, remote_controller_sold_amount, cd_player_sold_amount, av_processors_sold_amount;
    double tv_sales, dvd_sales, remote_controller_sales, cd_player_sales, av_processors_sales, subtotal, tax, total;
    
    //Input sold amount
    cout << "How many TVs were sold? " ;
    cin >> tv_sold_amount;
    cout << "How many DVD players were sold? " ;
    cin >> dvd_sold_amount;
    cout << "How many Remote Controller units were sold? " ;
    cin >> remote_controller_sold_amount;
    cout << "How many CD Players were sold? " ;
    cin >> cd_player_sold_amount;
    cout << "How many AV Processors were sold? " ;
    cin >> av_processors_sold_amount;
    cout << endl << endl;
    
    
    //Calculate the sales
    tv_sales = tv_sold_amount * TV_PRICE;
    dvd_sales = dvd_sold_amount * DVD_PRICE;
    remote_controller_sales = remote_controller_sold_amount * REMOTE_CONTROLLER_PRICE;
    cd_player_sales = cd_player_sold_amount * CD_PLAYER_PRICE;
    av_processors_sales = av_processors_sold_amount * AV_PROCESSOR_PRICE;
    subtotal = tv_sales + dvd_sales + remote_controller_sales + cd_player_sales + av_processors_sales;
    tax = subtotal * TAX_RATE;
    total = subtotal + tax;
    
    
    //Output the single products.
    cout << setprecision(2) << fixed;
    cout << left << setw(6) << "QTY" << setw(35) << "Description" << setw(18) << "Unit Price" << "Total Price" << endl;
    
    if ( tv_sold_amount != 0 )
    {
        cout << right << setw(3) << tv_sold_amount << setw(3) << " " << left << setw(35) << "TV" << setw(3) << "$" << right << setw(7) << TV_PRICE << setw(9) << "$" << right << setw(10) << tv_sales << endl;
    }
    
    if ( dvd_sold_amount != 0 )
    {
        cout << right << setw(3) << dvd_sold_amount << setw(3) << " " << left << setw(35) << "DVD" << setw(4) << "$" << right << setw(4) << DVD_PRICE << setw(9) << "$" << right << setw(10) << dvd_sales << endl;
    }
    
    if ( remote_controller_sold_amount != 0 )
    {
        cout << right << setw(3) << remote_controller_sold_amount << setw(3) << " " << left << setw(35) << "REMOTE CONTROLLER" << setw(5) << "$" << right << setw(4) << REMOTE_CONTROLLER_PRICE << setw(9) << "$" << right << setw(10) << remote_controller_sales << endl;
    }
    
    if ( cd_player_sold_amount != 0 )
    {
        cout << right << setw(3) << cd_player_sold_amount << setw(3) << " " << left << setw(35) << "CD PLAYER" << setw(5) << "$" << right << setw(4) << CD_PLAYER_PRICE << setw(9) << "$" << right << setw(10) << cd_player_sales << endl;
    }
    
    if ( av_processors_sold_amount != 0 )
    {
        cout << right << setw(3) << av_processors_sold_amount << setw(3) << " " << left << setw(35) << "AV PROCESSOR" << setw(3) << "$" << right << setw(4) << AV_PROCESSOR_PRICE << setw(9) << "$" << right << setw(10) << av_processors_sales << endl;
    }
    
    //output the total
    cout << endl;
    cout << left << setw(6) << " " << setw(35) << " " << setw(15) <<  "SUBTOTAL" << right << setw(4) << "$" << right << setw(10) << subtotal << endl;
    cout << left << setw(6) << " " << setw(35) << " " << setw(15) <<  "TAX" << right << setw(4) << "$" << right << setw(10) << tax << endl;
    cout << left << setw(6) << " " << setw(35) << " " << setw(15) <<  "TOTAL" << right << setw(4) << "$" << right << setw(10) << total << endl;
    
    return 0;
}



/* Out put
 Part I:
 
 How many TVs were sold? 13
 How many DVD players were sold? 2
 How many Remote Controller units were sold? 3
 How many CD Players were sold? 1
 How many AV Processors were sold? 21
 
 
 QTY   Description                        Unit Price        Total Price
 13    TV                                 $   500.00        $   6500.00
  2    DVD                                $   380.00        $    760.00
  3    REMOTE CONTROLLER                  $    35.20        $    105.60
  1    CD PLAYER                          $    74.50        $     74.50
 21    AV PROCESSOR                       $  1500.00        $  31500.00
 
                                          SUBTOTAL          $  38940.10
                                          TAX               $   3407.26
                                          TOTAL             $  42347.36
 Program ended with exit code: 0
 
 

 Part II:
 How many TVs were sold? 0
 How many DVD players were sold? 2
 How many Remote Controller units were sold? 0
 How many CD Players were sold? 1
 How many AV Processors were sold? 0
 
 
 QTY   Description                        Unit Price        Total Price
   2   DVD                                $   380.00        $    760.00
   1   CD PLAYER                          $    74.50        $     74.50
 
                                          SUBTOTAL          $    834.50
                                          TAX               $     73.02
                                          TOTAL             $    907.52
 Program ended with exit code: 0
 
 */
