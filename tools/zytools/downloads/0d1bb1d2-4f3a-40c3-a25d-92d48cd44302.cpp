#include <iostream>
using namespace std;

int main() {
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   
   cin >> caffeineMg;

   /* Type your code here. */
   double caffeineLeft;
   caffeineLeft = caffeineMg/2;
   cout << "After 6 hours: " << caffeineLeft << " mg" << endl;
   caffeineLeft = caffeineLeft / 2;
   cout << "After 6 hours: " << caffeineLeft << " mg" << endl;
   caffeineLeft = caffeineLeft / 2;
   cout << "After 6 hours: " << caffeineLeft << " mg" << endl;

   return 0;
}
