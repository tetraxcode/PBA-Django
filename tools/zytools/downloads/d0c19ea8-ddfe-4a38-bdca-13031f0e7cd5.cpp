#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   /* Type your code here. */
   int changePrice;
   int monthlyMortgage;
   changePrice = currentPrice - lastMonthsPrice;
   monthlyMortgage = (currentPrice*0.045)/12;
   
   cout <<"This hosue is $"; 
   cout << currentPrice; 
   cout << ".The current change is $"; 
   cout << changePrice; 
   cout << " since last month."<< endln;
   cout<< "The estimated monthly mortgage us $";
   cout << monthlyMortgage;
   cout << "." << endl;
   
   return 0;
}
