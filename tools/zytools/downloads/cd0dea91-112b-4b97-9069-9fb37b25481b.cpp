#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
   cout << "This house is ";
   cout << currentPrice;
   cout << ".";
   cout << "The change is ";
   cout << (lastMonthsPrice - currentPrice);
   cout << " since last month.";
   cout << endl;
   cout << The estimated monthly mortgate is";
   cout << (currentPricce*0.045)/12;
   cout << endl;

   return 0;
}
