#include <iostream>
using namespace std;

int main() {
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   
   cin >> caffeineMg;
   cout<<"After 6 hours: "<<caffeineMg/2<<" mg"<<endl;
   cout<<"After 12 hours: "<<caffeineMg/2/2<<" mg"<<endl;
   cout<<"After 18 hours: "<<caffeineMg/2/2/2<<" mg"<<endl;

   /* Type your code here. */

   return 0;
}
