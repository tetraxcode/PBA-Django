#include <iostream>
using namespace std;

int main() {
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   
   cin >> caffeineMg;

   /* Type your code here. */
   cout << "After 6 hours: " << caffeineMg *0.5 << endl;
   cout << "After 12 hours: " << caffeineMg *(0.5^2) << endl;
   cout << "After 18 hours: " << caffeineMg *(0.5^3) << endl;

   return 0;
}
