#include <iostream>
using namespace std;

int main() {
   double caffeineMg;  
   
   cin >> caffeineMg;
   
   double sixHours;
   double twelveHours;
   double eighteenHours;
   
   sixHours = caffeineMg / 2;
   twelveHours = sixHours / 2;
   eighteenHours = twelveHours / 2;
   

   cout << "After 6 hours: " << sixHours << " mg" << endl;
   cout << "After 12 hours: " << twelveHours << " mg" << endl;
   cout << "After 18 hours: " << eighteenHours << " mg" << endl;

   return 0;
}
