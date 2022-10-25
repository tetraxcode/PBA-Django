#include <iostream>
using namespace std;

int main() {
   int baseChar;
   int headChar;
   
   baseChar = 1;
   headChar = 0; 
   
   cout << "     " << baseChar;
   cout << endl; 
   cout << string(5, headChar) + float(2, baseChar);
   cout << endl;
   
   /* Type your code here. */

   return 0;
}
