#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int totalPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   cin >> totalPrice;
   totalPrice= currentPrice-lastMonthsPrice
lastMonthsPrice= currentPrice-lastMonthsPrice;

   /* Type your code here. */
cout<< "This house is "<< currentPrice<< ". The change is "<< lastMonthsPrice<< " since last month."<<endl;
cout<< "The estimated monthly mortgage is "<<totalPrice<<endl; 
   return 0;
}
