#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "The house is " << CurrentPrice << ". The change is $" << currentPrice-lastMonthPrice << " since last month." << endl;
   cout << "The estimated monthly mortgage is $" << (currentPrice*0.045)/12 << "." << endl;

   return 0;
}
