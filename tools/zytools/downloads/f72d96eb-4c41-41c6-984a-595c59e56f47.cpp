#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   float monthlyMortgage;
   int monDifference;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   
   monDifference = currentPrice - lastMonthsPrice;
   monthlyMortgage = (currentPrice * .045) / 12;
   
   
   
   cout << "This house is $" << currentPrice << ". The change is $" << monDifference << " since last month." << endl << "The estimated monthly mortgage is $" << monthlyMortgage << "." << endl;
   

   return 0;
}
