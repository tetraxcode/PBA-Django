#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   
   lastMonthsPrice - currentPrice  
   
   cout << "This house is " << currentPrice << ". The change is $";
   cout << lastMonthsPrice - currentPrice;
   cout << " since last month." << endl;
   cout << "The estimated monthly mortgage is ";
   cout << (currentPrice*0.045)/12; 
   cout << ".";
   
   /* Type your code here. */

   return 0;
}
