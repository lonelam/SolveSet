#include<bits/stdc++.h>
using namespace std;
int h[1050];
int V[1050];
int main()
{
    int n;
    while(cin >> n)
    {
        for (int i = 0; i < n; i++)

        {
            cin >> h[i];

        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int l = i;
            while(l >= 0 && h[l] >= h[i])
            {
                l--;
            }
            l++;
            int r = i;
            while(r < n && h[r] >= h[i])
            {
                r++;
            }
            r--;
            V[i] = h[i] * (r - l + 1);
          //  cout << V[i] << "  "<< i << endl;
            ans = max(V[i], ans);
        }
        cout << ans << endl;
    }
}
