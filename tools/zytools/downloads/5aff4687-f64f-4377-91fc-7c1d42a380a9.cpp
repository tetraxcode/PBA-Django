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
   lastMonthsPrice = 40000 ;
   currentPrice = 350000 ;
   cout << "This house is $" << currentPrice << ". The change is $" << lastMonthsPrice << " since last month." ;
   cout << endl ;
   monthlyMortgage = 1312.5 ;
   cout << "The estimated monthly mortgage is $" << monthlyMortgage << "." << endl ;

   return 0;
}