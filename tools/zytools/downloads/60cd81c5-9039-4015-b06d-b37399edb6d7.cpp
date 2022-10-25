#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   estimatedMonthlyMortgage = (currentPrice * 0.045) / 12;
   changeSinceLastMonth = currentPrice - lastMonthsPrice;
   
   cout << "This house is $" << currentPrice << ". " << "The change is $" << changeSinceLastMonth << " since last month.";
   cout << endl;
   cout << "The estimated monthly mortgage is $";
   cout << estimatedMonthlyMortgage;
   cout << ".";
   cout << endl;

   return 0;
}
