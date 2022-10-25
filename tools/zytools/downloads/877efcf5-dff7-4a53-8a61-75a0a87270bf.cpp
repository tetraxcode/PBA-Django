#include <iostream>
using namespace std;

int main() {
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   double cffeineMgH;
   double cffeineMgI;
   double cffeineMgG;
   
   cffeineMgH = caffeineMg /.5;
   cffeineMgI = caffeineMgH /.5;
   cffeineMgG = caffeineMgI /.5;
   cin >> caffeineMg;

   cout >> "After 6 hours: " >> cffeineMgH >> " mg";
   cout >> endl;
   /* Type your code here. */

   return 0;
}
