#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
    int N;
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> N)
    {
        int ans = -1;
        for (int i = 0; i < N; i++)
        {
          cin >> a[i];
        }
        sort(a, a + N);
        int cnt = 1;
        for (size_t i = 1; i < N; i++)
        {
            if (a[i] == a[i-1]) cnt++;
            else if (cnt > N / 2)
            {
                ans = a[i - 1];
                cnt = 1;
            }
            else cnt = 1;
        }
        cout << ans << endl;
    }
}
