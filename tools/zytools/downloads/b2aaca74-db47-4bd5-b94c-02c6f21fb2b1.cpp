#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

cout << "This house is 200000" << currentPrice << ". The change is -10000" << currentPrice - lastMonthsPrice << " since last month." <<
cout << "The estimated monthly mortgage is 750" << (currrentPrice*0.045)/12 << "." << endl;
   return 0;
}
