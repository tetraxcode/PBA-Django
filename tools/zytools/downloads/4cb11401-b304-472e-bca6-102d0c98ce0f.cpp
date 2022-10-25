#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;


   cout<<"This house is $" <<currentPrice<<". The change is $-"<<lastMonthsPrice<<" since last month.";
   cout<<"The estimated montly mortgage is $750."endl;

   return 0;
}
