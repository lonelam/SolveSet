#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, N;
    double m = 0;
    int mA, mB;
    cin >> N >> A >> B;
    for (int x = 1; x <= N; x++)
    {
        int y = (A * x - 1) / B;
        if (static_cast<double>(y) / x > m)
        {
            m = double(y) / x;
            mA = y;
            mB = x;
        }
    }
    cout << mA << " " << mB << endl;
}
