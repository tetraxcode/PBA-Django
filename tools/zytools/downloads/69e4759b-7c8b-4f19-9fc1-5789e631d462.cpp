#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << (currentPrice * 0.045/12) ;
   cout << lastMonthsPrice;
   cout << currentPrice;

   return 0;
}
