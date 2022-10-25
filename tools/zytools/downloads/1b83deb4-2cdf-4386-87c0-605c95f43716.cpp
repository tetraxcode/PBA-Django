#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int monthlyMortgage;
   int monDifference;
   
   monDifference = currentPrice - lastMonthsPrice;
   monthlyMortgage = (currentPrice * .045) / 12;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   
   couts << "This house is $" << currentPrice << ". The change is $" << monDifference << " since last month." << endl << "The estimated monthly mortgage is $" << monthlyMortgage << "." << endl;
   

   return 0;
}
