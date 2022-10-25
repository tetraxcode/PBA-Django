#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int mortgage;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   
   mortgage = (currentPrice*0.045)/12;
   lastMonthsPrice = (currentPrice - lastMonthsPrice);

   /* Type your code here. */
   cout << "This house is $" << currentPrice << ". The change is $" << lastMonthsPrice << "." <<endl;
   cout << "Thus estimated monthly mortgage is" << mortgage << "." <<endl;

   return 0;
}
