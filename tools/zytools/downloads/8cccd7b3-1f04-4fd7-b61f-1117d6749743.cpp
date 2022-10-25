#include <iostream>
using namespace std;

int main() {
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   double caffeineMg6;
   double caffeineMg12;
   double caffeineMg18;
   
   cin >> caffeineMg;
   
   caffeineMg6 = caffeineMg / 2;
   caffeineMg12 = caffeineMg6 / 2;
   caffeineMg18 = caffeineMg12 / 2;
   
   cout << "After 6 hours: " << caffeineMg6 << "mg" << endl;
   cout << "After 12 hours: " << caffeineMg12 << "mg" << endl;
   cout << "After 18 hours: " << caffeineMg18 << "mg" << endl;

   /* Type your code here. */

   return 0;
}
