#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is $" << current price << ". The change is $" << currentPrice - lastMonthsPrice << " since last month." << endl;
   cout << "The estimated monthly morgage is $" << (currentPrice * 0.045)/12 << endl;

   return 0;
}
