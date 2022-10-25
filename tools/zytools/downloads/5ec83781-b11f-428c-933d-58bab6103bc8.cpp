#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
lastMonthsPrice= currentPrice-lastMonthsPrice;

   /* Type your code here. */
cout<< "This house is $"<< currentPrice<< ". The change is $"<< lastMonthsPrice<< " since last month."<<endl;
cout<< "The estimated monthly mortgage is $"<<endl; 
   return 0;
}
