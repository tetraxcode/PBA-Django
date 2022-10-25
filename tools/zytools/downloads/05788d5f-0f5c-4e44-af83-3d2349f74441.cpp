#include <iostream>
using namespace std;

int main() {
   double caffeineMg;  // "double" supports floating-point like 75.5, versus int for integers like 75.
   
   cin >> caffeineMg;

   cout << "Your caffeine level after 6 hours will be: " << caffeineMg/2 " mg.";
   cout << "Your caffeine level after 12 hours will be: " << caffeineMg/4 " mg.";
   cout << "Your caffeine level after 18 hours will be: " << caffeineMg/8 " mg.";
   return 0;
}
