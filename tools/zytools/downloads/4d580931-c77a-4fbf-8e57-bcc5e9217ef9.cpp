#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
   cout << " This house is $" << cuurentPrice << "." << " The change is $" << (currentPrice * 0.045) / 12 << " since last month." <<endl;
   return 0;
}
