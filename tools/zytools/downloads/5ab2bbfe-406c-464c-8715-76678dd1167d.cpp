#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
   int priceChange = currentPrice - lastMonthsPrice;
   double monthlyMortgage = (currentPrice * 0.045) / 12;
   
   cout << "This house is $" << currentPrice << ". The change is $" << priceChange << " since last month." << endl;
   cout << "The estimated monthly mortgage is $" << monthlyMortgage << "." << endl;
   return 0;
}
