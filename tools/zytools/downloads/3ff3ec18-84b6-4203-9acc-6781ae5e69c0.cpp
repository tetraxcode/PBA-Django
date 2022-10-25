#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int mortgage;
   int Change;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   Change = lastMonthsPrice - currentPrice

   mortgage = currentPrice * 0.045 / 12 ;
   
   cout << "This house is $" << currentPrice << ". The change is $" << Change << " since last month. The estimated monthly mortgage is $" << mortgage << "." <<endl;

   return 0;
}
