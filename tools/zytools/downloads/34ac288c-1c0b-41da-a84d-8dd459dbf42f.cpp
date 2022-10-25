#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is $" << currentPrice << ".The change is $" << lastMonthsPrice -20000 << " since last month. " << endl;/* Type your code here. */
   cout << "The estimated monthly mortgage is $750." << endl;
   return 0;
}
