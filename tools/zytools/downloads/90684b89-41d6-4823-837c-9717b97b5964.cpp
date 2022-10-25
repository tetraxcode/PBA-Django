#include <iostream>
using namespace std;

int main() {
   string userName;
   cin >> userName;
      //cin used to accept the input from the standard input device
      //set for variable/string 'userName'
   cout << "Hello " << userName << ", and welcome to CS Online!" << endl;
      //will report value of string 'userName', not in commas because it needs to express its value, not count as characters of text
   return 0;
}