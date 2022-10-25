#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   cin >> estimatedMonthlyMortgage;
   lastMonthsPrice = currentPrice - 210000;
   estimatedMonthlyMortgage = (currentPrice * 0.045) / 12;
   
   cout << "This house is $" << currentPrice << ". " << "The change is $" << lastMonthsPrice << " since last month.";
   cout << endl;
   cout << "The estimated monthly mortgage is $";
   cout << estimatedMonthlyMortgage;
   cout << ".";
   cout << endl;

   return 0;
}
