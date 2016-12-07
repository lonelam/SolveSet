#include<algorithm>
#include<functional>
#include<iostream>
using namespace std;

int v[10020];

int main()
{
    int n, k;
    while(cin >> n >> k)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v, v + n, greater<int>());
        int ans = 0;
        for (int i = 0; i < k; i++)
        {
            ans += v[i];
        }
        cout << ans <<endl;
    }
}
