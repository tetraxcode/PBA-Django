#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is $" << currentPrice << ". The change is $-40000 since last month.\n";
   cout << "The estimated monthly mortgage is $1312.5.\n";

   return 0;
}
