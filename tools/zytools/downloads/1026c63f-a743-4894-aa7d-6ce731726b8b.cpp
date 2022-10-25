#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   lastMonthsPrice = (currentPrice * 0.045)/12

   cout << "This house is $";
   cout << currentPrice;
   cout << ". The change is $";
   cout << lastMonthsPrice;
   

   return 0;
}
