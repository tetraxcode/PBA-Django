#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is $" << currentPrice << ".The change is $;
   cout << currentPrice - lastMonthsPrice << " since last month. The estimated monthly mortgage is $";
   cout << (currentPrice * 0.45) / 12 << endl;

   return 0;
}
