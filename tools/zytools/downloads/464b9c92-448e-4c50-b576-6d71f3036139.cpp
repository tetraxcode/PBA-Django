#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is $" << currentPrice << ". The change is $" << currentPrice - lastMonthsPrice << " since last month." << endl;
   cout << "The estimated monthly mortgage is $" << currentPrice / 266.6667<< endl;

   return 0;
}
