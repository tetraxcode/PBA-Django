#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
   cout << "This house is $" << currentPrice << ". The change is $-2" << lastMonthsPrice << " since last month." ;
   cout << endl ;
   cout << "The estimated monthly mortgage is $750." ;
   cout << endl ;

   return 0;
}
