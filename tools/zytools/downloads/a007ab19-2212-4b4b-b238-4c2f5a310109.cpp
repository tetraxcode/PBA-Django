#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "The house is " << currentPrice << ". ";
   cout << "The change is $" << currentPrice-lastMonthsPrice << " since the last month." << endl;
   cout << "The estimated monthly mortgage is $" << (currentPrice*0.045)/12 << "." << endl;

   return 0;
}
