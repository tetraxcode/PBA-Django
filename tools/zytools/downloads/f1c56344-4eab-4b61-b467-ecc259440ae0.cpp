#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int newPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   cin >> newPrice;
newPricee= (currentPrice * .045)/12;
lastMonthsPrice= currentPrice-lastMonthsPrice;

   /* Type your code here. */
cout<< "This house is $"<< currentPrice<< ". The change is $"<< lastMonthsPrice << " since last month."<<endl;
cout<< "The estimated monthly mortgage is $"<< newPrice<< "."<<endl; 
   return 0;
}
