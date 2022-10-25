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

   cout << "This house is $" << currentPrice << ". " << endl;

   return 0;
}
