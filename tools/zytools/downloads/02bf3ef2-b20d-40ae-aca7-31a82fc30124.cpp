#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int priceChange;
   int MonthlyMorgage;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   priceChange = lastMonthsPrice - currentPrice;
   MonthlyMorgage = (currentPrice * 0.045) / 12;

   cout << "This house is " << currentPrice << " . The change is " << priceChange << " since last month. " << endl;
   cout << "The estimated monthly morgage is " << MonthlyMorgage << "." << endl;

   return 0;
}
