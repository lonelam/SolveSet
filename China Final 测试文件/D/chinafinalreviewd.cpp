#include<iostream>
using namespace std;
const int maxn = 100005;
bool nprime[maxn];
void init()
{
    nprime[1] = nprime[0] = true;
    for (int i = 2; i < maxn; i++)
    {
        if (!nprime[i])
        {
            for (int j = i + i; j < maxn; j+= i)
            {
                nprime[j] = true;
            }
        }
    }
}
int main()
{
    init();
    int n;

    while(cin >> n)
    {
        int ans = 0;
        int p;
        for (int i = 0; i < n; i++)
        {
            cin >> p;
            if (!nprime[p])
                ans++;

        }
        cout << ans <<endl;
    }
}
