#include <iostream>
using namespace std;

int main() {
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   
   cin >> caffeineMg;

   double sixH;
   sixH = caffeineMg/2;
   cout << "After 6 hours: " << sixH << " mg" << endl;
   
   double twlH;
   twlH = sixH/2;
   cout << "After 12 hours: " << twlH << " mg" << endl;
   
   double egtH;
   egtH = twlH/2;
   cout << "After 18 hours: " << egtH << " mg" << endl;
   

   return 0;
}
