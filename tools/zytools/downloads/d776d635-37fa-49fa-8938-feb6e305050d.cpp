#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice; 
   
   cin >> currentPrice;
   cin >> lastMonthsPrice; 
   
   cout << (currentPrice*0.045)/12

   cout << "This house is $" << currentPrice << ". The change is $-" << lastMonthsPrice << " since last month." << endl; 
   cout << "The estimated monthly mortgage is $750." << endl; 

   return 0;
}
