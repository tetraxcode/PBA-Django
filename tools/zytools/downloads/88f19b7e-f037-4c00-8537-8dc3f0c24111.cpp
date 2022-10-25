#include <iostream>
using namespace std;

int main() {
   int currentPrice = "200000";
   int lastMonthsPrice = "210000";
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   cout << "This house is " << currentPrice << "The change is " << lastMonthsPrice-currentPrice << "since last month" << endl;
   cout << "The estimated monthly mortgage is" << currentPrice*0.045;
   
   return 0;
}
