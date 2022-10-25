#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   //cout << "current price: ";
      cin >> currentPrice;
  // cout << "last month's price: ";   
      cin >> lastMonthsPrice;

   cout << "This house is $" << currentPrice << ".The change is $-" << lastMonthsPrice << " since last month." << endl;
   cout << "The estimated monthly mortage is $" << (currentPrice * 0.045) / 12 << ".";

   return 0;
}
