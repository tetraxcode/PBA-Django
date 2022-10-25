#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

   cout << " This house is " << currentPrce << ". The change is " << lastMonthsPrice << " since last month." << endl;
   cout << " The estimated monthly mortgage is " << (currentPrice*.045)/12 << " ." << endl;

   return 0;
}
