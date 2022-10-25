#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is $" << currentPrice << ".";
   cout << " The change is $" << - lastMonthsPrice << " since last month.";
   cout << "The estimated monthly mortgage is $" << currentPrice - lastMonthsPrice << "." << endl;/* Type your code here. */

   return 0;
}
