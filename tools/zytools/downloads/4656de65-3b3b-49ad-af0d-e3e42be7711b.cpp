#include <iostream>
using namespace std;

int main() {
   /* Variables */
   /* define variables here */
   int currentPrice;
   int lastMonthsPrice;
   
   /* establish process for variables*/
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* currentPrice and lastMonthsPrice are the variables*/
   cout << "This house is $" << currentPrice << ". The change is $";
   cout << currentPrice - lastMonthsPrice << " since last month." << endl;
   
   /* formula is (currentPrice x 0.045)/12; when value is input, the "process" will be completed giving the output- in this case $-10000 */
   cout << "The estimated monthly mortgage is $" << (currentPrice * 0.045) / 12 << "." << endl;
   
/* When inputting the values for the variables, make sure to just separate w/space; no comma is needed */
   return 0;
}
