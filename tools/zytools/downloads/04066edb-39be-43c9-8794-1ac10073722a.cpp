#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

  cout << "This house is $" << currentPrice << "." << endl;
  cout << "The change is " << lastMonthsPrice << " since last month." << endl;
  cout << "The estimated monthly mortgage is " << lastMonthsPrice << "." << endl; 

   return 0;
}
