#include <iostream>
using namespace std;

int main() {
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   
   cin >> caffeineMg;

   cout << "After 6 hours: " << caffeineMg * 0.5 << " mg" << endl;
   cout << "After 6 hours: " << caffeineMg * 0.25 << " mg" << endl;
   cout << "After 6 hours: " << caffeineMg * 0.0125 << " mg" << endl;
   
   return 0;
}
