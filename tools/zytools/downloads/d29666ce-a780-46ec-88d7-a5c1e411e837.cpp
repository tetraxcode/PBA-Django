#include <iostream>
using namespace std;

int main() {
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   
   cin >> caffeineMg;

   double caffeineMg6 = caffeineMg/2;
      
   
   double caffeineMg12 = caffeineMg6/2;


   double caffeineMg18 = caffeineMg12/2;
 
   
   cout << "After 6 hours: " <<caffeineMg6 <<"mg" <<endl;
   cout << "After 12 hours: " <<caffeineMg12 <<"mg" <<endl;
   cout << "After 18 hours: " <<caffeineMg18 <<"mg" <<endl;

   return 0;
}
