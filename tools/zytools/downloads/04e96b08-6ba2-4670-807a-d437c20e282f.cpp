#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int newPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   cin >> newPrice;
currentPrice= currentPrice-lastMonthsPrice;   
newPrice= (currentPrice * .045)/12;

   /* Type your code here. */
cout<< "This house is $"<< lastMonthsPrice<< ". The change is $"<< lastMonthsPrice<< " since last month."<<endl;
cout<< "The estimated monthly mortgage is $"<< newPrice<< "."<<endl; 
   return 0;
}
