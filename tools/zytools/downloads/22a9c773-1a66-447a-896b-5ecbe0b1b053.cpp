#include <iostream>
using namespace std;

int main() {
   int baseChar;
   int headChar;

   /* Type your code here. */
   cin >> baseChar;
   cin >> headChar;
   
   cout << "     ";
   cout << headChar << endl;
   cout << baseChar << baseChar << baseChar << baseChar << baseChar << headChar << headChar << endl;
   cout << baseChar << baseChar << baseChar << baseChar << baseChar << headChar << headChar << headChar << endl;
   cout << baseChar << baseChar << baseChar << baseChar << baseChar << headChar << headChar << endl;
   cout << "     ";
   cout << headChar << endl;

   return 0;
}
