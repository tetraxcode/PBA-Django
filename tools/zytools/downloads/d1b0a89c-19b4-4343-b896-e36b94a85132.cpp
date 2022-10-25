#include <iostream>
using namespace std;

int main() {
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   double halfcaffeineMg; 
   double quartercaffeineMg;
   double eighthcaffeineMg;   
   
   cin >> caffeineMg;
   cin >> halfcaffeineMg;
   cin >> quartercaffeineMg;
   cin >> eighthcaffeineMg;
   
   halfcaffeineMg= caffeineMg / 2;
   quartercaffeineMg= caffeineMg / 4;
   eighthcaffeineMg= caffeineMg / 8;
   
   cout << "After 6 hours: " << halfcaffeineMg << " mg" << endl; 
   cout << "After 12 hours: " << quartercaffeineMg << " mg" << endl;
   cout << "After 18 hours: " << eighthcaffeineMg << " mg" << endl;

   return 0;
}
