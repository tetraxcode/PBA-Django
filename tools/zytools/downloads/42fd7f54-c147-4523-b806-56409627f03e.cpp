#include <iostream>
using namespace std;

int main() {
   int baseChar;
   int headChar;

   cin >> baseChar;
   cin >> headChar;
   
   int x;
   for (x = 0 ; x < 5 ; x++)
      cout << " ";
   cout << headChar << endl;

   for (x = 0 ; x < 5 ; x++)
      cout << "0";
   cout << headChar << headChar << endl;
   

   return 0;
}
