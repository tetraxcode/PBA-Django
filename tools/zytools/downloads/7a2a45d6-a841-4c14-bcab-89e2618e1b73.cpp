#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is " << currentPrice << ". The change is " << currentPrice - lastMonthsPrice << " since last month. " << endl;
   cout << "The estimated monthly mortgage is " << endl;/* Type your code here. */

   return 0;
}
