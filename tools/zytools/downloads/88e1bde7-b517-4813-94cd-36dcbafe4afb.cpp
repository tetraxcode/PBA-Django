#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is $" << (currentPrice * 0.045) / 12 << "." << "The change is $-" << lastMonthsPrice << "since last month." << endl;
   cout << "The estimated monthly mortgage is $" << currentPrice << "." << endl;

   return 0;
}
