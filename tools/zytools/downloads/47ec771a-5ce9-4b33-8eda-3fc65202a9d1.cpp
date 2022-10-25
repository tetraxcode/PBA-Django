#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int newPrice;
   
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   
   
   
   newPrice = (currentPrice * 0.045) / 12;
   
   cout << "This house is $" << currentPrice << ". The change is $" << lastMonthsPrice << " since last month.";
   cout << endl;
   cout << "The estimated monthly mortgage is $" << (currentPrice * 0.045) / 12 << ".";

   return 0;
}
