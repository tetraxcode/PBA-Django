#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
   int change = currentPrice - lastMonthsPrice;
   int mortgage = (currentPrice * 0.045)/12;
   
   cout << "This house is $" << currentPrice << ". The change is $" << change << " since last month." << endl;
   cout << "The estimated monthly mortgage is $" << mortgage;
   cout << endl;

   return 0;
}
