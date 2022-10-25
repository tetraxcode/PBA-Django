#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is " << lastMonthsPrice << "." << "The change is " << currentPrice * 0.045/12 << " since last month." << endl;
   cout << "The estimated monthly mortage is " << currentPrice << endl;

   return 0;
}
