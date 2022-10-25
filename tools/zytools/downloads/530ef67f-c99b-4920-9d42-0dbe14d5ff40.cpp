#include <iostream>
using namespace std;

int main() {
   String baseChar;
   String headChar;

   /* Type your code here. */
   //Inputting base and head chars.
   cin >> baseChar;
   cin >> headChar;
   
   //Printing the arrow 
   cout << "     "<<headChar<<endl;
   cout << baseChar <<baseChar <<baseChar <<baseChar <<baseChar <<headChar <<headChar<<endl;
   cout << baseChar <<baseChar <<baseChar <<baseChar <<baseChar <<headChar <<headChar <<headChar <<endl;
   cout << baseChar <<baseChar <<baseChar <<baseChar <<baseChar <<headChar <<headChar<<endl;
   cout << "     "<<headChar<<endl;

   return 0;
}
