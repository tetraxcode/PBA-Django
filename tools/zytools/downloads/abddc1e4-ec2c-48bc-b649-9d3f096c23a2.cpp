#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int estMonthly; 
   
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   cin >> estMonthly;
   
   cout << "This house is $" << currentPrice << ". The change is $-" << lastMonthsPrice<< " since last month." << endl; 
   estMonthly = (currentPrice * 0.045) / 12; 
   cout << "The estimated monthly mortgage is $" << estMonthly << "." << endl; 

   /* Type your code here. */

   return 0;
}
