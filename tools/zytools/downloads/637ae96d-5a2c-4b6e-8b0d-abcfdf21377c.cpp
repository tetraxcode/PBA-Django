#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int change; 
   int mortgage ; 
   change = currentPrice - lastMonthsPrice ;
   mortgage = (currentPrice * 0.045)/12 ;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   cout << "This house is $" << currentPrice << ". The change is $" << change << " since last month." << endl ;
   cout << "The estimated monthly mortgage is $" << mortgage << "." << endl ;
   

   
   cout << "This house is" << currentPrice << ". The change is 

   return 0;
}
