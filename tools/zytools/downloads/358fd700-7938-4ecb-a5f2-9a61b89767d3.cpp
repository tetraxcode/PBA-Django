#include <iostream>
using namespace std;

int main() {
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   int timeX;
   cin >>timeX;
   cin >> caffeineMg;

   cout << caffeineMg/(2timeX) << endl;

   return 0;
}
