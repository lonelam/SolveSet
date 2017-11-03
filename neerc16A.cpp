#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 +10;
int a[maxn];
int n;
int L[maxn], R[maxn];

vector<int> disc;

int main()
{
    while(cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

        }
        int m = max_element(a, a + n) - a;
        cout << ((m + n - 1) % n +1) << " "<< (m +1)  << " "<< ((m + 1) % n + 1) << endl;
    }
}
