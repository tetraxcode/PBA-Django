#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is " << currentPrice << ". The change is ";
   cout << currentPrice * 0.045 / 12;

   return 0;
}
