#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */

   cout << "This house is " << currentPrice << ". the change is $" << currentPrice-lastMonthPrice << "since last month." << endl;
   cout << "The estimated monthly mortgage is" << currentPrice*0.045 << "." << endl;
   return 0;
}
