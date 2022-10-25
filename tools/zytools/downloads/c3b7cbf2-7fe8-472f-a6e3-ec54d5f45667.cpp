#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   
   int priceChange = currentPrice - lastMonthsPrice;

   /* Type your code here. */
   cout << "This house is " << currentPrice << ". The change is " << priceChange << " since last month." << endl;
   cout << "This estimated monthly morgage is " << currentPrice * 0.045 / 12;
   cout << endl;

   return 0;
}
