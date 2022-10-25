#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int change;
   int mortgage;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   
   change = currentPrice - lastMonthsPrice;
   /* Type your code here. */
   cout << "This house is $" << currentPrice << ".";
   cout << "The change is $" << change << " since last month." << endl;
   cout << "The estimated monthly mortgage is $" << (currentPrice * 0.045) / 12 << "." << endl;
   return 0;
}
