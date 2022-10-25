#include <iostream>
using namespace std;

int arraySize(*int arr){
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    return arrSize;
}

int main() {
   int baseChar;
   int headChar;

   unsigned short arrow[5][8] = {
      {0,0,0,0,0,2,0,0},
      {1,1,1,1,1,2,2,0},
      {1,1,1,1,1,2,2,2},
      {1,1,1,1,1,2,2,0},
      {0,0,0,0,0,2,0,0}
   };
   
   for (unsigned i = 0; i < arrSize(arrow); i++){
   
   }
)

   return 0;
}
