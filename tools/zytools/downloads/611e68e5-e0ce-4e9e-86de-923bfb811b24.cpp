#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   
   totalPrice= currentPrice - lastMonthsPrice
   monthlyMorgage= currentPrice * 0.045 / 12 

   cout << "This house is $" << currentPrice << ". The change is $" << totalPrice << "since last month." << endl;
   cout << "The estimated monthlt morgage is $" << monthlyMorgage << "." << endl;

   return 0;
}
