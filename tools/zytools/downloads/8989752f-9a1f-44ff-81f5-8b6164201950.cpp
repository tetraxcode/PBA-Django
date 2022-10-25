#include <iostream>
using namespace std;

int main() {
   int baseChar;
   int headChar;

   cin >> baseChar >> headChar;
   
   cout << "     " << headChar << endl;                                                                           //layer 1
   cout << baseChar << baseChar << baseChar << baseChar << baseChar << headChar << headChar << endl;              //layer 2
   cout << baseChar << baseChar << baseChar << baseChar << baseChar << headChar << headChar << headChar << endl;  //layer 3
   cout << baseChar << baseChar << baseChar << baseChar << baseChar << headChar << headChar << endl;              //layer 4
   cout << "     " << headChar << endl;                                                                           //layer 5
   
   return 0;
}
