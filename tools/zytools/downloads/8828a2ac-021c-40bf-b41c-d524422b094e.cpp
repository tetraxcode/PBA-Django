#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is " << currentPrice << ". The change is ";
   cout << lastMonthsPrice - currentPrice;
   cout << " since last month. The estimated monthly mortgage is ";
   cout << currentPrice * 0.045 / 12;
   cout << ".";

   return 0;
}
