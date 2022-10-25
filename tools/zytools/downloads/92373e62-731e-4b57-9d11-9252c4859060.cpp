#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int changePrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
  // changePrice is the change in the price :)//
  changePrice = currentPrice - lastMonthsPrice ;
   
   cout << "This house is $" << currentPrice;
   cout << ". The change is $" << changePrice << " since last month." << endl;
   
   cout << "The estimated monthly mortgage is $" << (currentPrice * 0.045) / 12 << "." << endl;
   
   
   return 0;
}
