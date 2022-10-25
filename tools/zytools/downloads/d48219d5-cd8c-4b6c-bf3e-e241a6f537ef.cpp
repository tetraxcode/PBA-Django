#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int estimatedMonthlyMortgage;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   cin >> estimatedMontlyMortagage;
   estimatedMonthlyMortgage = (currentPrice * 0.045) / 12;
   lastMonthsPrice = currentPrice - 210000;
   
   cout << "This house is " << currentPrice << ". " << "The change is $" << lastMonthsPrice << " since last month.";
   cout << endl;
   cout << "The estimated montly mortgage is $" << estimatedMontlyMortgage << ".";
   cout << endl;

   return 0;
}
