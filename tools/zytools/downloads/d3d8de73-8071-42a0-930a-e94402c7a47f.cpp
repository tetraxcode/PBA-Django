#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int estimatedMortgage = currentPrice * 0.045 / 12;
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is " << currentPrice << ".";
   cout << " The change is $" << lastMonthsPrice<< " since last month." << endl;
   cout << "The estimated monthly mortgage is " << estimatedMortgage << endl;

   return 0;
}
