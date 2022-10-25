#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout<<"This house is $"<<currentPrice<<endl;
   cout<<"The change is $"<<(currentPrice - lastMonthsPrice)<<endl;
   cout<<"The estimated monthly mortgage is $"<<(currentPrice * 0.051) / 12); 

   return 0;
}
