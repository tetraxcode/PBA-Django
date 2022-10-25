#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
cout >> ("This house is $%d. The change is $%d since last month.\n", currentPrice, currentPrice - lastMonthsPrice);
   cout>> ("The estimated monthly mortgage is $" + ((currentPrice * 0.051) / 12) + "."); 
}
   return 0;
}
