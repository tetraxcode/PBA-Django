#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int changePrice;
   int mortgage;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   cin >> changePrice;
   cin >> mortgage;
   changePrice = currentPrice - lastMonthsPrice;
   mortgage = (currentPrice * 0.045) / 12

   cout << "This house is $" << currentPrice << ". " << "The change is $" << changePrice << " since last month." << endl;
   cout << "The estimated monthly mortgage is $" << mortgage << "." << endl;

   return 0;
}
