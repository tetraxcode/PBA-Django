#include <iostream>
using namespace std;

int main() {
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   
   cin >> caffeineMg;

   cout << "After 6 hours: " << caffeineMg << " mg" << endl;
   caffeineMg = caffeineMg / 2;
   
   cout << "After 12 hours: " << caffeineMg << " mg" << endl;
   caffeineMg = caffeineMg / 2;
   
   cout << "After 18 hours: " << caffeineMg << " mg" << endl;
   
   return 0;
}
