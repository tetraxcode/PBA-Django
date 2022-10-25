#include <iostream>
using namespace std;

int main() {
   char baseChar;
   char headChar;
   int lenArrow;
   int i;
   
   cin >> baseChar >> headChar >> lenArrow;
   
   for(i=1; i <= lenArrow; i++ ) cout << " ";
   cout << headChar << endl;
   for(i=1; i <= lenArrow; i++ ) cout << baseChar;
   cout << headChar << headChar << endl;
   for(i=1; i <= lenArrow; i++ ) cout << baseChar;
   cout << headChar << headChar << headChar<< endl;
   for(i=1; i <= lenArrow; i++ ) cout << baseChar;
   cout << headChar << headChar << endl;
   for(i=1; i <= lenArrow; i++ ) cout << " ";
   cout << headChar << endl;
   
   return 0;
}
