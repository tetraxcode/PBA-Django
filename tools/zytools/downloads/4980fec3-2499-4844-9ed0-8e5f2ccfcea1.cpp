#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int monthlyMortgage;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   cin >> monthlyMortgage;

   /* Type your code here. */
   cout << "This house is $" << currentPrice << ". The change is $-" << lastMonthsPrice << " since last month." ;
   cout << endl ;
   monthly mortgage = (currentPrice * 0.045) / 12 ;
   cout << "The estimated monthly mortgage is $" << monthly mortgage << "." ;
   cout << endl ;

   return 0;
}
