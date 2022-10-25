#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout<< "This house is $" << currentPrice << ". The change is $" << lastMonthsPrice<< " since last month. The estimated monthy mortgage is $"<< (currentPrice * .045)/12<<endl;

   return 0;
}
