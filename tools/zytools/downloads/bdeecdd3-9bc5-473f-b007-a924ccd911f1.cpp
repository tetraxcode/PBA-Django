#include <iostream>
using namespace std;

int main() {
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   double caffeineMgH;
   double caffeineMgI;
   double caffeineMgG;
  
   cin >> caffeineMg;
   caffeineMgH = caffeineMg *.5;
   caffeineMgI = caffeineMgH *.5;
   caffeineMgG = caffeineMgI *.5;
   

   cout << "After 6 hours: " << caffeineMgH << " mg";
   cout << endl;
   cout << "After 12 hours: " << caffeineMgI << " mg";
   cout << endl;
   cout << "After 18 hours: " << caffeineMgG << " mg";
   cout << endl;
   /* Type your code here. */

   return 0;
}
