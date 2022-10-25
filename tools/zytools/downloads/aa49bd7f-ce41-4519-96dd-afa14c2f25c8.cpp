#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   cin >> currentPrice;
CurrentPrice= (CurrentPrice * .045)/12;
lastMonthsPrice= currentPrice-lastMonthsPrice;

   /* Type your code here. */
cout<< "This house is $"<< currentPrice<< ". The change is $"<< lastMonthsPrice<< " since last month."<<endl;
cout<< "The estimated monthly mortgage is $"<< CurrentPrice<< "."<<endl; 
   return 0;
}
