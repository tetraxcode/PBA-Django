#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
   cout << "This house is " << currentPrice; << "the change is" << currentPrice-lastMonthsPrice << " since last month. The estimated monthy morgage is " << (currentPirce*.045) << "." ; 
   cout << endl;
   return 0;
}
