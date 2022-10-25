#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   currentPrice = 200000;
   lastMonthsPrice= 210000;
   
   cout << "This house is $" << currentPrice << ". The change is " << lastMonthsPrice-currentPrice << " since last month." << endl;
   cout << "The estimated monthly mortgage is $" << (currentPrice*0.045)/12 << "." << endl;

   return 0;
}
