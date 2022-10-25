#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   
   int monthlyMortgage = ( currentPrice * .045) /12

   cout << "This house is $" << currentPrice <<;
   cout << ". The change is $-1000 since last month." << endl;
   cout << "The estimated monthly mortgage is $" << monthlyMortgage << "." << endl;

   return 0;
}
