#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int a[maxn];
int vis[maxn];

int main()
{
    int n;
    int k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    int left = n;
    int lead = 0;
    memset(vis,0,sizeof(vis));
    for (int i = 0; i < k; i++)
    {
        a[i] %= left;
        int j = lead;
        for (; a[i] ; j = (j + 1) % n)
        {
            if (!vis[j])
            {
                a[i]--;
            }
        }

        while(vis[j]) j = (j+1)%n;
        vis[j] = 1;
        a[i] = j + 1;
        left--;
        lead = (j + 1) % n;
    }
    for (int i = 0; i < k; i++)
    {
        cout << a[i] <<" ";
    }
}
