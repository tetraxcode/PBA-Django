#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   int estimatedMonthly = currentPrice * 0.045/12;

   cout << "This house is " << currentPrice << "." << " The change is $-" << lastMonthsPrice << " since last month." << endl;
   cout << "The estimated monthly mortgage is" << estimatedMonthly << "." << endl;
   /* Type your code here. */

   return 0;
}
