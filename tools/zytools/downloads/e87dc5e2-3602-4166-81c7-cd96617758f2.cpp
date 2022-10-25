#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int change;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   
   change = currentPrice - lastMonthsPrice;
   /* Type your code here. */
   cout << "This house is " << currentPrice << ".";
   cout << "The change is " << change << "since last month.";
   return 0;
}
