#include <iostream>
using namespace std;

int main() {
   string currentPrice;
   cin >> currentPrice;
   string lastMonthsPrice;
   cin >> lastMonthsPrice;
   string findDiff

  cout << "This house is $" << currentPrice << ". The change is $" << findDiff(currentPrice, lastMonthsPrice) << " since last month. The estimated monthly mortgage is " << (currentPrice*0.045)/12 << "." << endl;

   return 0;
}
