#include <iostream>
using namespace std;

int main() {
   int baseChar;
   int headChar;
   
   cin >> baseChar;
   cin >> headChar;

   unsigned short arrow[5][8] = {
      {0,0,0,0,0,2,3,3},
      {1,1,1,1,1,2,2,3},
      {1,1,1,1,1,2,2,2},
      {1,1,1,1,1,2,2,3},
      {0,0,0,0,0,2,3,3}
   };
   
   for (unsigned i = 0; i < 5; i++){
      for (unsigned j = 0; j < 8; j++){
         switch (arrow[i][j]){
            case 0:
               cout << " ";
               break;
            case 1:
               cout << baseChar;
               break;
            case 2:
               cout << headChar;
               break;
            default:
               break;
         }
      }
        cout << endl;
   }

   return 0;
}
