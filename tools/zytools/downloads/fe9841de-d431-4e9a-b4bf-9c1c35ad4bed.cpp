#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;


   cout<<"This house is $" <<currentPrice<<". The change is $-"<<lastMonthsPrice<<" since last month.";
   cout<<"The estimated montly mortgage is" <<currentPrice * 0.045/ 12<< ".";
   cout<<endl;

   return 0;
}
