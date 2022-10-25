#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
    int estimatedMortgage = (currentPrice * 0.045) /12;
    int changePrice = currentPrice - lastMonthsPrice ;
   

   cout << "This house is $" << currentPrice << ". The change is $" << changePrice << " since last month." ;
   cout << endl ;
   cout << "The estimated monthly mortgage is $" << estimatedMortgage << ".";
   cout << endl;


   return 0;
}
