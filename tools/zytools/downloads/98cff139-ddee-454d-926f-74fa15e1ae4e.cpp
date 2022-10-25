#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int mortgage;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   mortgage = currentPrice * 0.045 / 12 ;
   
   cout << "This house is $" << currentPrice << ". The change is $" << lastMonthsPrice << " since last month. The estimated monthly mortgage is $" << mortgage << "." <<endl;

   return 0;
}
