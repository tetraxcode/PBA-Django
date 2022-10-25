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
      cout << baseChar;
   cout << headChar << headChar << endl;

   for (x = 0 ; x < 5 ; x++)
      cout << baseChar;
   cout << headChar << headChar << headChar << endl;
   
   for (x = 0 ; x < 5 ; x++)
      cout << baseChar;
   cout << headChar << headChar << endl;
   
   for (x = 0 ; x < 5 ; x++)
      cout << " ";
   cout << headChar << endl;
   

   return 0;
}
