#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int morgage;
   
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   morgage = (0.045 * currentPrice) / 12;
   
   
   cout << "This house is $" << currentPrice << ". The change is $" << currentPrice - lastMonthsPrice << " since last month.";
   cout << endl;
   cout << "The estimated monthly mortgage is $" << setprecision(5) << morgage << "."; 
   cout << endl;
   /* Type your code here. */

   return 0;
}
