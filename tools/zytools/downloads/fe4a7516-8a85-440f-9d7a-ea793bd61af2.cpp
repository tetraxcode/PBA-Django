#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
    cin >> changePrice;
   cin >> estimatedMonthlyMortage;

   /* Type your code here. */
   
   changePrice = lastMonthsPrice - currentPrice;
   
   
   cout << "This house is $" << currentPrice << ". The change is $-" << changePirce << " since last month." << endl;
   
   estimatedMonthlyMortage = (currentPrice * 0.045) / 12;
   
   cout << "The estimated monthly mortgage is $" << estimatedMonthlyMortage << "." << endl;
   
   
   
   return 0;
}
