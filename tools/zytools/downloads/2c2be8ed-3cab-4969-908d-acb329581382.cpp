#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
   cout << "This house is $" << currentPrice << "." << endl;
   cout << "The change is $" << (currentPrice - lastMonthsPrice) << "." << endl;
   cout << "The estimated monthly mortgage is $" << ((currentPrice*0.045) / 12 ) << endl;

   return 0;
}
