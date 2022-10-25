#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int monthlyMortgage;
   int priceChange;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   cin >> monthlyMortgage;
   cin >> priceChange;

   /* Type your code here. */
   priceChange = currentPrice - lastMonthsPrice ;
   cout << "This house is $" << currentPrice << ". The change is $" << lastMonthsPrice << " since last month." ;
   cout << endl ;
   monthlyMortgage = (currentPrice * 0.045) / 12 ;
   cout << "The estimated monthly mortgage is $" << monthlyMortgage << "." << endl ;

   return 0;
}
