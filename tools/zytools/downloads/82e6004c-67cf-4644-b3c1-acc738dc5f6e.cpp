#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

cout << "This house is $" << currentPrice << ". The change is $-1000 since last month." << endl;
cout << "The estimated monthly mortage is $" << lastMonthsPrice << endl;
   return 0;
}
