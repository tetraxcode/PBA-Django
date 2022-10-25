#include <iostream>
using namespace std;

int main() {
   double caffeineMg;
   
   cin >> caffeineMg;

   cout << "After 6 hours: " << caffeineMg / 2.0 << " mg" << endl;
   cout << "After 12 hours: " << caffeineMg / 4.0 << " mg" << endl;
   cout << "After 18 hours: " << caffeineMg / 6.0 << " mg" << endl;


   return 0;
}
