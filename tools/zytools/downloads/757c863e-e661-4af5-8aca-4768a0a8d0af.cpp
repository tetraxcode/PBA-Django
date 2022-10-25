#include <iostream>
using namespace std;

int main() {
   char baseChar;
   char headChar;
   int lenArrow;
   int widArrow;
   int i;
   
   cin >> baseChar >> headChar >> lenArrow >> widArrow;
   
   for(i=1; i <= lenArrow; i++ ) cout << " ";
   cout << headChar << endl;
   for(i=1; i <= lenArrow; i++ ) cout << baseChar;
   cout << headChar << headChar << endl;
   
   cout <<baseChar<<baseChar<<baseChar<<baseChar<<baseChar<<headChar<<headChar<< endl;
   cout <<baseChar<<baseChar<<baseChar<<baseChar<<baseChar<<headChar<<headChar<<headChar<< endl;
   cout <<baseChar<<baseChar<<baseChar<<baseChar<<baseChar<<headChar<<headChar<< endl;
   cout <<"     " << headChar << endl;
   
   return 0;
}
