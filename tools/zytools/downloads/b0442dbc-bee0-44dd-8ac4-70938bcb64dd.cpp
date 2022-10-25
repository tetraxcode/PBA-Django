#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   /* int changePrice;
   int estimatedMortgage; */
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   
   double monthlyMortgage = (currentPrice * 0.045) / 12;
   
  /* changePrice = currentPrice - lastMonthsPrice;
   estimatedMortgage = ((currentPrice * 0.045) / 12); */

   cout << "This house is $" << currentPrice << "." << " The change is $" << currentPrice - lastMonthsPrice << " since last month." << endl;
   cout << "The estimated monthly mortgage is $" << monthlyMortgage << "." << endl;
   

   return 0;
}
