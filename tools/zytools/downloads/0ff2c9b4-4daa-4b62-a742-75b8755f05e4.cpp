#include <iostream>
using namespace std;

int main() {
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   
   cin >> caffeineMg;

   cout << "AFter 6 hours: " << caffeineMg / 2 << endl; 
   cout << "AFter 12 hours: " << caffeineMg / 4 << endl; 
   cout << "AFter 18 hours: " << caffeineMg / 6 << endl; 

   return 0;
}
