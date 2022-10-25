#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
   
   changePrice = lastMonthsPrice - currentPrice;
   cin >> changePrice;
   
   cout << "This house is $" << currentPrice << ". The change is $-" << changePirce << " since last month." << endl;
   
   estimatedMonthlyMortage = (currentPrice * 0.045) / 12;
   cin >> estimatedMonthlyMortage;
   
   cout << "The estimated monthly mortgage is $" << estimatedMonthlyMortage << "." << endl;
   
   
   
   return 0;
}
