#include <iostream>
using namespace std;

int main() {
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   
   cin >> caffeineMg;

   /* Type your code here. */
   double halfCaffeine;
   double quarterCaffeine;
   double eighthCaffeine;
   halfCaffeine = caffeineMg * (1/2);
   quarterCaffeine = caffeineMg * (1/4);
   eighthCaffeine = caffeineMg * (1/8);
   
   cout << "After 6 hours: ";
   cout << halfCaffeine << endl;
   cout << "After 12 hours: ";
   cout << quarterCaffeine << endl;
   cout << "After 18 hours: ";
   cout << eighthCaffeine << endl;
   

   return 0;
}
