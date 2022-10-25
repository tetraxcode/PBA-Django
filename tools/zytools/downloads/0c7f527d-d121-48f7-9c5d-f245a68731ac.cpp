#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << "This house is "<< currentPrice<<". The change is "<< lastMonthsPrice << "since last month."<<endl;
   cout << "The estimated monthy mortage is" <<lastMonthsPrice*3.75 /1000 <<endl;

   return 0;
}
