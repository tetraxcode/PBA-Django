#include <iostream>
using namespace std;

int main() {
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   
   cin >> caffeineMg;

   /* Type your code here. */
   double halfCaffeine;
   double quarterCaffeine;
   double eighthCaffeine;
   halfCaffeine = caffeineMg * (0.5);
   quarterCaffeine = caffeineMg * (0.25);
   eighthCaffeine = caffeineMg * (0.125);
   
   cout << "After 6 hours: ";
   cout << halfCaffeine;
   cout << " mg" << endl;
   cout << "After 12 hours: ";
   cout << quarterCaffeine;
   cout << " mg" << endl;
   cout << "After 18 hours: ";
   cout << eighthCaffeine;
   cout << " mg" << endl;
   

   return 0;
}
