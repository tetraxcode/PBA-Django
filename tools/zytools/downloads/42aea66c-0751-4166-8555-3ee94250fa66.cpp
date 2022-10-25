#include <iostream>
using namespace std;

int main() 
{
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   int Times;
   int i, d, h; 
   
   cin >> caffeineMg >> Times;

   d=2; h=6;
   for( i=1; i<=Times; i++ ) 
   {
      cout << "After " << h << " hours: " << caffeineMg/d << " mg" << endl;
      h = h+6; 
      d = 2*d;
   }

   return 0;
}
