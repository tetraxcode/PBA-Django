#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   change = lastMonthsPrice - currentPrice;

   /* Type your code here. */
   cout << "This house is " << currentPrice << ". The change is " << change << " since last month. The estimated monthly mortgage is " << (currentPrice*0.045)/12 << endl;

   return 0;
}
