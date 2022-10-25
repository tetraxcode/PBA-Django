#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is $";
   cout << currentPrice;
   cout << ". The change is $";
   cout << lastMonthsPrice-currentPrice;

   return 0;
}
