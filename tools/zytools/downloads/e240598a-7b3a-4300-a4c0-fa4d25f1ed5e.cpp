#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int priceDifference;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   
   priceDifference = currentPrice - lastMonthsPrice;

   cout << "This house is $" << currentPrice << "." << " The change is $" << priceDifference << " since last month." << endl;
   cout << "The estimated monthly mortgage is $" << (currentPrice * 0.045)/12 << "." << endl;

   return 0;
}
