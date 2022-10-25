#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
int newprice = currentPrice - lastMonthsPrice;

cout << "This house is $" << currentPrice << ". The change is $" << newprice << " since last month." << endl;
cout << "The estimated monthly mortgage is $" << currentPrice*.045/12<<"." << endl;
   return 0;
}
