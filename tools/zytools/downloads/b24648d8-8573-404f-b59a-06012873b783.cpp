#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
   cout << "THis house is" << currentPrice;
   cout << "The change is" << lastMonthsPrice-currentPrice;
   cout << "The estimated monthly mortgage is 750.";
   cout << endl;

   return 0;
}
