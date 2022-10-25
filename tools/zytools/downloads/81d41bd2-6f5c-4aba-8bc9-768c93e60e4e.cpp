#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout<<"This house is"<<currentPrice<<". The change is"<<lastMonthsPrice - currentPrice<<"since last month."<<endl;
   /* Type your code here. */

   return 0;
}
