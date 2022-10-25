#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   cin >> currentPrice;
currentPrice= (currentPrice * .045)/12;

   /* Type your code here. */
cout<< "This house is $"<< currentPrice<< ". The change is $"<< lastMonthsPrice<< " since last month."<<endl;
cout<< "The estimated monthly mortgage is $"<< currentPrice<< "."<<endl; 
   return 0;
}
