#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
cout << "This house is $" << currentPrice;
cout << ".The change is $" << currentPrice - lastMonthsPrice << endl;
   return 0;
}
