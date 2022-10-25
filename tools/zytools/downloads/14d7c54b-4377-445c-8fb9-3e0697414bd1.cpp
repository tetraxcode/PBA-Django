#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   
   int changePrice; 
   changePrice = currentPrice - lastMonthsPrice;
   
   //int monthlyMortgage;
   //monthlyMortgage = 

   cout <<"This house is $" <<currentPrice <<"." <<" The change is $" <<changePrice << " since last month." <<endl;
   //cout <<"The estimated monthly mortgage is" <<
   return 0; 
}
