#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */

   cout << "This house is $" << currentPrice << "." << " The change is $" << (lastMonthsPrice - currentPrice) << "." << endl;

   return 0;
}
