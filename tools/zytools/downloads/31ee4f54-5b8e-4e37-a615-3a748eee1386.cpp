#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
   // The first output statement is used for calcuating and stating the change in current price from last month's price.
   cout << "This house is $200000. The change is $" << currentPrice - lastMonthsPrice << " since last month." << endl;
   //The second output statement is used for estimating the monthly mortgage, based off the predefined program input and above equation.
   cout << "The estimated monthly mortgage is " << (currentPrice * 0.045) / 12 << "." << endl;
   
   return 0;
}
