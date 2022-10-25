#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int changeLastMonth;
   int avgPrice;
   
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   cin >> changeLastMonth; 
   cin >> angPrice;
   
   changeLastMonth = currentPrice - lastMonthsPrice; 
   
   avgPrice = (currentPrice * 0.045) / 12; 
  
   
   cout << "This house is $" << currentPrice << ". The change is $-" << changeLastMonth << " since last month." << endl; 
   cout << "The estimated monthly mortgage is $" << avgPrice << "." << endl; 

   /* Type your code here. */

   return 0;
}
