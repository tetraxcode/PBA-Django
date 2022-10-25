#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
int newprice = currentPrice - lastMonthsPrice;
int morgage = currentPrice*.045*1/12;
cout << "This house is " << currentPrice << ". The change is $" << newprice << "since last month." << endl;
cout << "The estimated monthly morage is " << morgage;
   return 0;
}
