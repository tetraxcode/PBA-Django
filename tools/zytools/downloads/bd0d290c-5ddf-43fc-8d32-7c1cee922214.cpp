#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
   int changePrice ;
   int monthlyMortgage;
   changeprice = currentPrice - lastMonthsPrice;
   monthlyMortgage = (currentPrice*0.045)/12
   
   cout<<"This hosue is $" << currentPrice << ".The current change is $" << changePrice << " since last month.<< enddln;
   cout<< " The estimated monthly mortgage us $"<< monthlyMortgage << "." << endl;
   return 0;
}
