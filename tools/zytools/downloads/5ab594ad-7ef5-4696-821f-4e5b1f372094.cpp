#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   
   int changePrice; 
   changePrice = lastMonthsPrice - currentPrice;

   cout <<"This house is $" <<currentPrice <<"." <<" The change is $" <<changePrice << "since last month." <<endl;
   return 0;
}
