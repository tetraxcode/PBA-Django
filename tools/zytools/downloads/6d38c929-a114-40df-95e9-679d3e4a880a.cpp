#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /*calculating change and mortage/
   change=currentPrice-lastMonthsPrice
   mortgage=(currentPrice*0.051)/12*/
   
   cout<<"This house is"<<currentPrice<<". The change is"<<lastMonthsPrice - currentPrice<<"since last month."<<endl;
   cout<<"The estimated monthly mortgage is $"<<curreentPrice/0.00425<<"."<<endl;
   /* Type your code here. */

   return 0;
}
