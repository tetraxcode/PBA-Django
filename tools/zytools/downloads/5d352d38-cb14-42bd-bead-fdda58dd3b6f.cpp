#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   //cout << "current price: ";
      cin >> currentPrice;
  // cout << "last month's price: ";   
      cin >> lastMonthsPrice;

   cout << "This house is $" << currentPrice << ". The change is $" << lastMonthsPrice - currentPrice << " since last month." << endl;
   cout << "The estimated monthly mortgage is $" << (currentPrice * 0.045) / 12 << "." << endl;

   return 0;
}
