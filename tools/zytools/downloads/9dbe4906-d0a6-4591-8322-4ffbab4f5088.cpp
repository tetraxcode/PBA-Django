#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int estimatedMonthlyMortgage;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   lastMonthsPrice = currentPrice - 210000;
   
   cout << "This house is " << currentPrice << ". " << "The change is $" << lastMonthsPrice << " since last month.";
   cout << endl;
   cout << "The estimated montly mortgage is $750.";
   cout << endl;

   return 0;
}
