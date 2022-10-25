#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int avgMonth; 
   
   cin >> currentPrice;
   cin >> lastMonthsPrice; 
   cin >> avgMonth; 

   cout << "This house is " << currentPrice << ". The change is " << lastMonthsPrice << " since last month." << endl; 
   cout << "The estimated monthly mortgage is " << avgMonth << "." << endl; 

   return 0;
}
