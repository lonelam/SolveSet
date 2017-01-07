#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <stack>
#include <deque>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 100;
const ll moder = 1e10 + 7;
int idx(char x)
{
    return x - 'a';
}

char s[maxn];
int main()
{
    int n, nc;
    while(scanf("%d%d", &n,&nc)!=EOF)
    {
        scanf("%s", s);
        int m = strlen(s);
        ll hash = 0;
        ll biter = 1;
        set<ll> htable;
        hash = (hash + biter * idx(s[0])) % moder;
        for (int i= 1; i < nc; i++)
        {
            biter = (biter * 10007LL) % moder;
            hash = (hash + biter * idx(s[i])) % moder;
        }
        int cnt = 0;
        for (int i = 1; i + nc <= m; i++)
        {
            cnt++;
            set<ll>::iterator it = htable.lower_bound(hash);
            if (it != htable.end() && *it == hash) cnt--;
            else htable.insert(hash);
            hash = (hash - biter * idx(s[i - 1]) + moder) % moder;
            hash = (hash * 10007LL) % moder;
            hash = (hash + idx(s[i + nc - 1]))% moder;
        }
        cnt++;
        set<ll>::iterator it = htable.lower_bound(hash);
        if (it != htable.end() && *it == hash) cnt--;
        else htable.insert(hash);
        printf("%d\n", cnt);
    }
}
