#include <iostream>
using namespace std;

int main() {
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   
   cin >> caffeineMg;

  cout << "After 6 hours: " << caffeineMg/2 << " mg" << endl;
  cout << "Afer 12 hours: " << caffeineMg/4 << " mg" << endl;
  cout << "After 18 hours: " << caffeineMg/8 << " mg" << endl;

   return 0;
}
