#include <iostream>
using namespace std;

int main() {
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   
   cin >> caffeineMg;

   /* Type your code here. */
cout << "After 6 hours: " << (caffeineMg/6) << "mg" << endl; 
cout << "After 12 hours: " << (caffeineMg/12) << "mg" << endl; 
cout << "After 18 hours: " << (caffeineMg/18) << "mg" << endl; 

   return 0;
}
