#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   changeinPrice= currentPrice-lastMonthsPrice
   monthlyMortgage= (currentPrice * 0.045) / 12;
   
   cout<< "This house is $";
   cout<< currentPrice;
   cout<< ".";
   cout<< " The change is $";
   cout<< changeinPrice;
   cout<< " since last month.";
   cout<< endl;
   cout<< "The estimated monthly mortgage is $";
   cout<< monthlyMortgage;
   cout<< ".";
   cout<< endl;
   

   return 0;
}
