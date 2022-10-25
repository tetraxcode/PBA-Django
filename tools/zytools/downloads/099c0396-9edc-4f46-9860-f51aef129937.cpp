#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int priceChange;
   int MonthlyMortgage;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   priceChange = lastMonthsPrice - currentPrice;
   MonthlyMortgage = (currentPrice * 0.045) / 12;

   cout << "This house is $" << currentPrice << ". The change is $" << priceChange << " since last month." << endl;
   cout << "The estimated monthly mortgage is $" << MonthlyMortgage << "." << endl;

   return 0;
}
