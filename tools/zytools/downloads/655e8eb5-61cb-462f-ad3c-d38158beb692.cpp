#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is";
   cout << currentPrice;
   cout <<  ". The change is ";
   cout << currentPrice-lastMonthsPrice;
   cout << "since last month.";
   cout << endl;
   cout << "The estimated monthly mortage is ";
   cout << (currentPrice * 0.045) / 12 << ".";
   cout << endl;
   return 0;
}
