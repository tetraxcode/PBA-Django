#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice; 
   cin >> lastMonthsPrice;

   cout << "This house is ";
   cin >> currentPrice;
   cout << ".";
   cout << " The change is ";
   cin >> lastMonthsPrice;
   cout << " since last month.";
   cout << endl;
   cout << "The estimated monthly mortgage is";
   cin >> (currentPrice * 0.045) / 12;
   cout << ".";
   cout << endl;

   return 0;
}
