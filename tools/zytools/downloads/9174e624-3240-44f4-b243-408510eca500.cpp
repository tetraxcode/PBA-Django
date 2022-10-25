#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int newPrice;
   
   newPrice = (currentPrice * 0.045) / 12;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   cin >> newPrice;
   
   cout << "This house is $" << currentPrice << ". The change is $" << lastMonthsPrice << " since last month.";
   cout << endl;
   cout << "The estimated monthly mortgage is " << newPrice << "." << endl;

   return 0;
}
