#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
   
   print("This house is ${}. The change is ${} since last month.".format(currentPrice, currentPrice - lastMonthsPrice))
   
   print("The estimated monthly mortgage is ${:.2f}.".format((currentPrice * 0.045) / 12))
   
   return 0;
}
