#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is " << currentPrice <<"." << "The change is $" << currentPrice - lastMonthsPrice << " since last month.";

   return 0;
}
