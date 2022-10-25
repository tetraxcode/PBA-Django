#include <iostream>
using namespace std;

int main() {
   int baseChar;
   int headChar;
   int lenArrow;
   int widArrow;
   int i;
   
   cin >> baseChar >> headChar >> lenArrow >> widArrow;
   
   for(i=1; i <= lenArrow; i++ ) cout << " " << endl;
   for(i=1; i <= lenArrow; i++ ) cout << baseChar << endl;
   cout <<baseChar<<baseChar<<baseChar<<baseChar<<baseChar<<headChar<<headChar<< endl;
   cout <<baseChar<<baseChar<<baseChar<<baseChar<<baseChar<<headChar<<headChar<<headChar<< endl;
   cout <<baseChar<<baseChar<<baseChar<<baseChar<<baseChar<<headChar<<headChar<< endl;
   cout <<"     " << headChar << endl;
   
   return 0;
}
