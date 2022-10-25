#include <iostream>
using namespace std;

int main() 
{
   // declare a variable named userName of the type string
   string userName;
   // display a prompting message to get the first name

   cout << "Hello Pat, and welcome to CS Online! \n";
   
   // read input from keyboard
   cin >> userName;
   // print the results
   cout << "Hello " << userName << ", and welcome to CS Online!";

   return 0;
}