#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;


   cout<<"This house is "<< currentPrice<<". The change is $-"<<lastMonthsPrice<<" since last month."<<endl;
   cout<<"The estimated monthly morgage is $"<<lastMonthsPrice-currentPrice<<endl;

   return 0;
}
