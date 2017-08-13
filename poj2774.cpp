#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include <iostream>
#include<ctime>
#include<set>
#include<vector>
using namespace std;
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef long long ll;
typedef unsigned long long  ull;
const int MAXN = 1000010;
//ll gao[MAXN];
ll BL, BR, ML, MR;
ull psl[MAXN],psr[MAXN];
void Hash2(int n){
    for(int i = 0; i <= n ; i ++){
        psl[i] = (i == 0 ? 1 : psl[i - 1] * BL) % ML;
    }
    for(int i = 0 ; i <= n; i ++){
        psr[i] = (i == 0 ? 1 : psr[i - 1] * BR) % MR;
    }
}
void init(){
    int maxx = 1e9;
    srand(time(0));
    BL = (ll)maxx + rand() % maxx;
    BR = (ll)maxx + rand() % maxx;
    ML = (ll)maxx + rand() % maxx;
    MR = (ll)maxx + rand() % maxx;
}
struct __hash{
    //read your string in here.
    char str[MAXN];
    ull hs[MAXN];
    void build(){
        int n = strlen(str);
        ll l = 0, r = 0;
        for(int i = 0 ; i < n ; i ++){
            l = (l * BL + str[i]) % ML;
            r = (r * BR + str[i]) % MR;
            if(l < 0) l+= ML;
            if(r < 0)r += MR;
            hs[i + 1] = (l << 32) | r;
        }
    }
    ll get(int b,int e){
        ull el = (hs[e] >>32);
        ull er = (hs[e] & 0xffffffffULL);
        ull bl = (hs[b] >> 32);
        ull br = (hs[b] & 0xffffffffULL);
        ll l = el - bl * psl[e-b] % ML;
        ll r = er - br *psr[e-b] % MR;
        if(l < 0) l += ML;
        if(r < 0) r += MR;
        return (l << 32) | r;
    }
}Hash[2];
ll htable[MAXN];
int main()
{
    scanf("%s%s", Hash[0].str,Hash[1].str);
    int n = strlen(Hash[0].str);
    int m = strlen(Hash[1].str);
    int l = 1, r = min(n, m);
    int ans = 0;
    init();
    Hash2(max(n, m));
    Hash[0].build();
    Hash[1].build();
    while(l <= r)
    {
        const int mid = (l + r) / 2;
        for (int i = 0; i + mid <= n; i++)
        {
            ll hh = Hash[0].get(i, i + mid);
            htable[i] = hh;
            //cout << hh << endl;
        }
        sort(htable, htable + n - mid + 1);
        bool hit = false;
        for (int i = 0; !hit && i + mid <= m; i++)
        {
            ll hh = Hash[1].get(i, i + mid);
        //    cout << hh << endl;
            if (binary_search(htable, htable + n - mid + 1, hh))
            {
                hit = true;
            }
        }
//        cout << mid << endl;
        if (hit)
        {
            l = mid + 1;
            ans = max(ans, mid);
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%d\n", ans);
}
