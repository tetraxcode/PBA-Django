#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
   cout << "This house is $" << currentPrice << ".";
   cout << "The change is $" << lastMonthsPrice - currentPrice;
   cout << "since last month." << endl;
   cout << "The estimated monthly mortage is is $" << currentPrice*0.045/12;
   cout << "." << endl;

   return 0;
}
