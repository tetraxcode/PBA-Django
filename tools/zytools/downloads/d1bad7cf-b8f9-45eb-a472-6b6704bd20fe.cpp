#include <iostream>
#include <iomanip> // for std::setprecision()
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
   
   cout << "The estimated monthly mortgage is $"<< setprecision(2) << fixed << mortgage <<endl;

   return 0;
}
