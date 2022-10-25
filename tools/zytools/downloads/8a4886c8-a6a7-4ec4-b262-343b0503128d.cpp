#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int totalPrice;
   double monthlyMortgage;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   cin >> totalPrice;
   cin >> monthlyMortgage;
   
   totalPrice= currentPrice - lastMonthsPrice;
   monthlyMortgage= currentPrice * 0.045 / 12;

   cout << "This house is $" << currentPrice << ". The change is $" << totalPrice << " since last month." << endl;
   cout << "The estimated monthly mortgage is $" << monthlyMortgage << "." << endl;

   return 0;
}
