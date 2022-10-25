#include <iostream>
using namespace std;

int main() 
{
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   int Times;
   int i, d, h; 
   
   cin >> caffeineMg >> Times;

   h=6; d=2; 
   for( i=1,h=6,d=2; i<=Times; i++,h+=6,d*=2 ) 
   {
      cout << "After " << h << " hours: " << caffeineMg/d << " mg" << endl;

   }

   return 0;
}
