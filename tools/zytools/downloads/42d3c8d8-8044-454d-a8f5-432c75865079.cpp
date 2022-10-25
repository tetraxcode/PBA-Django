#include <iostream>

using namespace std;

int main()
{
    double caffeineMg;

    cin >> caffeineMg;

    cout << "After 6 hours: " << (caffeineMg * 0.5) << " mg" << endl;
    cout << "After 12 hours: " << (caffeineMg * 0.25) << " mg" << endl;
    cout << "After 18 hours: " << (caffeineMg * 0.125) << " mg" << endl;

    return 0;
}