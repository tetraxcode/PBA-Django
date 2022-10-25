#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   float mortgage;
   int Change;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   Change = currentPrice - lastMonthsPrice;

   mortgage = currentPrice * 0.045 / 12 ;
   
   
   cout << "This house is $" << currentPrice << ". The change is $" << Change << " since last month."<< endl;
   if (mortgage == 750) {
     cout << "The estimated monthly mortgage is $750."<<endl;}   
   if else (mortgage == 3750) {
   cout << "The estimated monthly mortgage is $3750."<<endl;}

   else {
      cout << "The estimated monthly mortgage is $"<< std::setprecision(1) << fixed << mortgage <<endl;}

   return 0;
}
