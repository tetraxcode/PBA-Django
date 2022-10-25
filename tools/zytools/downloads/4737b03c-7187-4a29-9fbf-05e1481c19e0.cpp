#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
   cout << "This house is $" << currentPrice;
   cout << "The change is $" << currentPrice-lastMonthsPrice;
   cout << "since last month.";
   cout << endl;
   cout << "The estimated monthly mortgage is $" <<  (currentPrice*0.045)/12;
   cout << endl;

   return 0;
}
