#include <iostream>
using namespace std;

int main() {
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   
   cin >> caffeineMg;

   /*caffeineMg = caffeineMg / 2;
   cout<<"After 6 hours: "<<caffeineMg<<" mg"<<endl;
   caffeineMg = caffeineMg / 2;
   cout<<"After 12 hours: "<<caffeineMg<<" mg"<<endl;
   caffeineMg = caffeineMg / 2;
   cout<<"After 18 hours: "<<caffeineMg<<" mg"<<endl;*/
   
   temp = 6;
   for (int i = 0; i < temp; i = i + 1)
   {
      caffeineMg = caffeineMg / 2;
      cout<<"After "<<6 + i*6<<" hours: "<<caffeineMg<<" mg"<<endl;
   }

   return 0;
}
