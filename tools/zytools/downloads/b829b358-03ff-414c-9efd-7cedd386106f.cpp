#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int changePrice;
   int mortgagePrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
  // changePrice is the change in the price :)//
  changePrice = lastMonthsPrice - currentPrice;
   
   cout << "This house is $" << currentPrice;
   cout << ". The change is $" << changePrice << "since last month." << endl;
   
   mortgagePrice = (currentPrice * 0.045) / 12;
   cout << "The estimated monthly mortgage is $" << mortgagePrice << "." << endl;
   
   
   return 0;
}
