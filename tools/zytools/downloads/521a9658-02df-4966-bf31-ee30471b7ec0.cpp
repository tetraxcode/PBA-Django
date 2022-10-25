#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is $" << currentPrice << ". The change is $" << currentPrice - lastMonthsPrice << " since last month."
   cout >> endl << "The estimated monthly mortgage is $750." << endl;/* Type your code here. */

   return 0;
}
