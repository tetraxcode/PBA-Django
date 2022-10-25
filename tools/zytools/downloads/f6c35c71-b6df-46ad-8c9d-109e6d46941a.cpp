#include <iostream>
using namespace std;

int main() {
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   
   cin >> caffeineMg;

   cout << "After 6 hours: " << caffeineMg/2 << endl;
   cout << "After 12 hours: " << caffeineMg/4 << endl;
   cout << "After 18 hours: " << caffeineMg/16 << endl;

   return 0;
}
