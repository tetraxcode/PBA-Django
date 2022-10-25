#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;
  
  
   

   cout << "This house is $";
   cout << currentPrice; 
   cout << ".";
   cout << " The change is $-10000 since last month.";
   cout << endl;
   cout << "The estimated monthly mortgage is $";
   cout<< (currentPrice * 0.045) / 12;
   cout << ".";
   cout << endl;
   
    cin >> currentPrice;
   cin >> lastMonthsPrice;
    
    
   cout << "This house is $";
   cout << currentPrice; 
   cout << ".";
   cout << " The change is $40000since last month.";
   cout << endl;
   cout << "The estimated monthly mortgage is $";
   cout<< (currentPrice * 0.045) / 12;
   cout << ".";
   cout << endl;
 

   return 0;
}
