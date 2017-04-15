#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int a[maxn];
int ans[maxn];
int main()
{
    int n;
    while(cin >> n)
    {
        for (int i = 0 ; i < n; i++)
        {
            cin >> a[i];
        }
        stack<int> s;
        //sort(a, a + n);
        int p = 1;

        ans[0] = 1;
        for (int i = 0; i < a[0]; i++)
        {
            s.push(p++);
            //p++;
        }
        s.pop();
        for (int i = 1; i < n; i++)
        {
            if (a[i] > a[i - 1])
            {
            //    a.push(1);
                ans[i] = 1;
                //p += a[i] - a[i - 1];
                for (int j = 0; j < a[i] - a[i - 1]; j++)
                {
                    s.push(p++);
                }
                s.pop();
            }
            else
            {
                ans[i] = p - s.top();
                s.pop();
            }
        }
        cout << ans[0];
        for (int i = 1; i < n; i++)
        {
            cout <<" "<< ans[i];
        }
        cout << endl;
    }
}
