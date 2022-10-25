#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice; 
   
   cin >> currentPrice;
   cin >> lastMonthsPrice; 
   
   monthlyMortgage = (currentPrice*0.045)/12;

   cout << "This house is $" << currentPrice << ". The change is $-" << lastMonthsPrice << " since last month." << endl; 
   cout << "The estimated monthly mortgage is $" << monthlyMortgage << "." << endl; 

   return 0;
}
