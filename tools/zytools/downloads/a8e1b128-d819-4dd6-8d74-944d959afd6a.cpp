#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is $" << currentPrice << "." << "The change is $";
   priceDiff = currentPrice - lastMonthsPrice;
   cout << " since last month." << endl;
   monthMortgage = (currentPrice * 0.045) / 12;
   cout << "The estimated monthly mortgage is $" << monthMortgage << endl;

   return 0;
}
