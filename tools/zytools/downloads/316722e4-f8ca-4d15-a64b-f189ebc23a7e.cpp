#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int change;
   int mortgage;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   
   change = currentPrice - lastMonthsPrice;
   mortgage = (currentPrice*0.045)/12
   /* Type your code here. */
   cout << "This house is " << currentPrice << ".";
   cout << "The change is " << change << " since last month.";
   cout << "The estimated monthly mortgage is " >> mortgage >> "."
   return 0;
}
