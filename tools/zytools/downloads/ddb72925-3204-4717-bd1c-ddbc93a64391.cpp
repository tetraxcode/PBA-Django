#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

cout << "This house is $" << currentPrice << "." << "The change is $" << (currentPrice - lastMonthsPrice) << endl;
cout << "The estimated month mortgage is $" << ((currentPrice * 0.045)/12);

   return 0;
}
