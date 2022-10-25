#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int changePrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   cin >> changePrice;
   changePrice = currentPrice - lastMonthsPrice;

   cout << "This house is $" << currentPrice << "The change is $" << changePrice << " since last month." endl;
   cout << "The estimated monthly mortgage is $750" endl;

   return 0;
}
