#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
   cout << "This house is $" << currentPrice << ".";
   cout << "The charge is $" << currentPrice - lastMonthsPrice << "since last month." << endl;
   cout << "The estimated monthly mortage is $" << (currentPrice * 0.045)/12 << "." << endl;

   return 0;
}
