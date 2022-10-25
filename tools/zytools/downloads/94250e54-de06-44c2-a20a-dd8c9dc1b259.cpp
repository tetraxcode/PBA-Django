#include <iostream>
using namespace std;

int main() {
   string currentPrice;
   cin >> currentPrice;
   string lastMonthsPrice;
   cin >> lastMonthsPrice;
   string findDiff(currentPrice, lastMonthsPrice);
   cout << findDiff(currentPrice, lastMonthsPrice);

  cout << "This house is $" << currentPrice << ". The change is $" << findDiff(currentPrice, lastMonthsPrice) << " since last month. The estimated monthly mortgage is " << (currentPrice*0.045)/12 << "." << endl;

   return 0;
}
