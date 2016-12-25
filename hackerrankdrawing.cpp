#include <iostream>
using namespace std;

int main()
{
    int n, p;
    while(cin >> n >> p)
    {
        cout << min(p / 2, (n  / 2 - p / 2) )<< endl;
    }
}
