#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int priceChange;
   int monthlyMortgage;
   
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   priceChange = currentPrice - lastMonthsPrice;
   monthlyMortgage = (currentPrice * 0.045) / 12;
   
   cout << "This house is $" << currentPrice << ". The change is $" << priceChange << " since last month." << endl;
   cout << "The estimated monthly mortgage is $" << monthlyMortgage << "." << endl;
   
   return 0;

   /* Type your code here. */

   return 0;
}
