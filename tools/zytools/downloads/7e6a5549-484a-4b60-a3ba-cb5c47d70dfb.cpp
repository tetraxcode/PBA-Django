#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int Sum;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   sum = lastMonthsPrice - currentPrice;
   
   cout <<"This house is $" <<currentPrice;
   cout <<". The change is $-" <<Sum;
   cout <<" since last month." <<endl;
   cout <<"The estimated monthly mortgage is $"  <<(currentPrice * 0.045) /12;
   cout <<"." <<endl;
   /* Type your code here. */

   return 0;
}
