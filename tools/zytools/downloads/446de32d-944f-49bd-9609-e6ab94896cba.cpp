#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;


        cout<<"\nThis house is $"<<currentPrice<<". The change is $"<<currentPrice-lastmonthPrice<<" since the last month.\n";
        cout<<"The estimated monthly mortgage is $"<<(currentPrice*0.045)/12;
}
