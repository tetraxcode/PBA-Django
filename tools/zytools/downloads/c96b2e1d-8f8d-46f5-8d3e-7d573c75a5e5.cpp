#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is ";
   cout << "$";
   cout << currentPrice;
   cout << ".";
   cout << " The change is ";
   cout << "$";
   cout << "-";
   cout << currentPrice-lastMonthsPrice;
   cout << " since last month.";
   cout << endl;
   cout << "The estimated monthly mortgage is ";
   cout << "$";
   cout << (currentPrice * 0.045)/12;
   cout << ".";
   cout << endl;

   return 0;
}
