#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is $" << currentPrice << ". The change is $" << currentPrice - lastMonthPrice;
   cout << " since last month. The estimated mortgage is $" << currentPrice * 0.045 << ".\n";

   return 0;
}
