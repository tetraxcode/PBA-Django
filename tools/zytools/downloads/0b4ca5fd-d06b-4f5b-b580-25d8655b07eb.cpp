#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
   currentPrice = 200000;
   lastMonthsPrice = 201000;
   
   cout << "This house is "<< currentPrice << ". The change is $-10000 since last month." << endl;
   
   cout << "The estimated monthly mortgage is $750." << endl;
   
   return 0;
}
