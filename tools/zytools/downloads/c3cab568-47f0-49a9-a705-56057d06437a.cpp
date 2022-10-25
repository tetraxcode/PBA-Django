#include <iostream>
using namespace std;

int main() {
   int currentPrice=0 ;
   int lastMonthsPrice=0;
   int change=0; 
   int mortgage=0 ; 
   change = currentPrice - lastMonthsPrice ;
   mortgage = (currentPrice * 0.045)/12 ;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   cout << "This house is $" << currentPrice << ". The change is $" << change << " since last month." << endl ;
   cout << "The estimated monthly mortgage is $" << mortgage << "." << endl ;
   

   

   return 0;
}
