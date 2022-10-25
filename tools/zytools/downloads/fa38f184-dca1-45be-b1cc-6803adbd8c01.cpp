#include <iostream>
using namespace std;

int main() {
   int baseChar;
   int headChar;

   cin >> baseChar;
   cin >> headChar;
   
   cout << \t << headChar << endl;
   cout << baseChar << baseChar << baseChar << baseChar << baseChar << headChar << headChar << endl;
   cout << baseChar << baseChar << baseChar << baseChar << baseChar << headChar << headChar << headChar << endl;
   cout << baseChar << baseChar << baseChar << baseChar << baseChar << headChar << headChar << endl;
   cout << \t << headChar << endl;
   
   return 0;
}
