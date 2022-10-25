#include <iostream>
using namespace std;

int main() {
   int baseChar;
   int headChar;

int main()
{
    int baseChar;
    int headChar;
    int lineArrow = 1;

    cin >> baseChar;
    cin >> headChar;

    for (int i = 0; i < 5; i++)
    {
        switch (lineArrow)
        {
        case 1:
            cout << "     " << headChar << endl;
            break;
        case 2:
            for (int a = 0; a < 5; a++)
            {
                cout << baseChar;
            }
            cout << headChar << headChar << endl;
            break;
        case 3:
            for (int a = 0; a < 5; a++)
            {
                cout << baseChar;
            }
            cout << headChar << headChar << headChar << endl;
            break;
        case 4:
            for (int a = 0; a < 5; a++)
            {
                cout << baseChar;
            }
            cout << headChar << headChar << endl;
            break;
        case 5:
            cout << "     " << headChar << endl;
            break;
        }
        lineArrow++;

   return 0;
}
