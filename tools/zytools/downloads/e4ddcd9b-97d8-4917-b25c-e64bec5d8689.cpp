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
   
   cout<<"This house is $"<<currentPrice<<". The change is $"<<currentPrice-lastMonthsPrice<<" since last month."<<endl;
   cout<<"The estimated monthly mortgage is $"<<currentPrice/266.6667<<"."<<endl;
   /* Type your code here. */

   return 0;
}
