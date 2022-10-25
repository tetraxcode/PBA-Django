#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   int mortgage;
   int Change;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   Change = currentPrice - lastMonthsPrice;

   mortgage = currentPrice * 0.045 / 12 ;
   
   cout << "This house is $" << currentPrice << ". The change is $" << Change << " since last month."<< endl; 
   std::cout << std::setprecision(5) << "The estimated monthly mortgage is $" << mortgage << "." <<'\n';

   return 0;
}
