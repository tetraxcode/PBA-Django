#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is $" << currentPrice - lastMonthPrice << ". The change is $" << priceChange << " since last month." << endl;
   cout << "The estimated monthly mortgage is $" << (currentPrice * 0.045) / 12 << "." << endl;
   return 0;
}
