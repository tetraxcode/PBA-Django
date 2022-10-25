#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int morgage;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   morgage = 0.0045 * currentPrice / 12;
   
   
   
   cout << "This house is $" << currentPrice << ". This change is $-" << lastMonthsPrice << " since last month";
   cout << endl;
   cout << " The estimadted monthly mortgage is $" << morgage << "."; 
   cout << endl;
   /* Type your code here. */

   return 0;
}
