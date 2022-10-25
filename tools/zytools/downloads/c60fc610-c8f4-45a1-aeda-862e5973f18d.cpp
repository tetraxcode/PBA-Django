#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is $" << currentPrice;
   cout << ". The change is $" << lastMonthsPrice - currentPrice << " since last month.";

   return 0;
}
