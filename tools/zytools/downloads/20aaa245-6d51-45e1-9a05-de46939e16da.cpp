#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   monthlyMorgage = currentPrice * 0.045/12;

   cout << "This house is " << currentPrice << "." << "The change is " << currentPrice - lastMonthsPrice << " since last month." << endl; 
   cout << "The estimated monthly mortgage is $ " << monthlyMorgage << "." << endl;/* Type your code here. */

   return 0;
}
