#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   
   int changeOfPrice;
       changeOfPrice = lastMonthsPrice - currentPrice; 
       
   cout << "This house is $" << currentPrice << "." << " The change is $" << changeOfPrice << " since last month." << endl;
   cout << "The estimated monthyl mortgage is $" << (currentPrice * 0.045) / 12 << "." << endl;

   /* Type your code here. */

   return 0;
}
