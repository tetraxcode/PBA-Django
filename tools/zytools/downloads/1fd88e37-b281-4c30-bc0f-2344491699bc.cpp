#include <iostream>
using namespace std;

int main() {
   int currentPrice=0 ;
   int lastMonthsPrice=0;
   int change; 
   int mortgage ; 
  
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   change = currentPrice - lastMonthsPrice ;
   mortgage = (currentPrice * 0.045)/12 ;
   cout << "This house is $" << currentPrice << ". The change is $" << change << " since last month." << endl ;
   cout << "The estimated monthly mortgage is $" << mortgage << "." << endl ;
   

   

   return 0;
}
