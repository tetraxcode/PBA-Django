#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
  
  
   

   cout << "This house is";
   cout << currentPrice;
   cout << "The change is $ -10000 since last month."
   cout << lastMonthsPrice;
   cout << (currentPrice * 0.045) / 12;
 

   return 0;
}
