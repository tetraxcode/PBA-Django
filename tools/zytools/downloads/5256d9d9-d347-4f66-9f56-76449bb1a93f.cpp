#include <iostream>
#include <iomanip>
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
   
   cout << "The estimated monthly mortgage is $"<< std::setprecision(5) << fixed << mortgage <<endl;

   return 0;
}
