#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int monthlyMortgage;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
   cout << "/n This house is " << currentPrice << ". ";
   cout << "The change is " << (currentPrice-lastMonthsPrice) << " since last month.";
   
   (monthlyMortgage-currentPrice *0.045)/12;
   cout << "/n The estimated monthly mortgage is " << monthlyMortgage << ".";

   return 0;
}
