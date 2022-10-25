#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
   cout << "this house is $" << currentPrice << "." << " The change is $" << lastMonthsPrice-currentPrice << " since lat month." <<endl; 
   cout << "The estimated monthly mortgage is $" << (currentPrice * 0.045) / 12 << "."; 
   return 0;
}
