#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
//#include <iostream>
#include<ctime>
#include<set>
#include<vector>
using namespace std;
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define rep(X,N) for(int X=0;X<N;X++)
typedef pair<int,int> PII;
typedef long long ll;
const int MAXN = 1000010;
//ll gao[MAXN];
struct{
    ll BL,BR,ML,MR;
    unsigned long long psl[MAXN],psr[MAXN];
    char str[MAXN];
    unsigned long long hs[MAXN];
    void Hash2(int n){
        for(int i = 0; i <= n ; i ++){
            psl[i] = (i == 0 ? 1 : psl[i - 1] * BL) % ML;
        }
        for(int i = 0 ; i <= n; i ++){
            psr[i] = (i == 0 ? 1 : psr[i - 1] * BR) % MR;
        }
    }
    void build(){
        int n = strlen(str);
        long long l = 0, r = 0;
        for(int i = 0 ; i < n ; i ++){
            l = (l * BL + str[i]) % ML;
            r = (r * BR + str[i]) % MR;
            if(l < 0) l+= ML;
            if(r < 0)r += MR;
            hs[i + 1] = (l << 32) | r;
        }
    }
    long long get(int b,int e){
        unsigned long long el = (hs[e] >>32);
        unsigned long long er = (hs[e] & 0xffffffffULL);
        unsigned long long bl = (hs[b] >> 32);
        unsigned long long br = (hs[b] & 0xffffffffULL);
        long long l = el - bl * psl[e-b] % ML;
        long long r = er - br *psr[e-b] % MR;
        if(l < 0) l += ML;
        if(r < 0) r += MR;
        return (l << 32) | r;

    }
    void init(){
        int maxx = 1e9;
        BL = (ll)maxx + rand() % maxx;
        BR = (ll)maxx + rand() % maxx;
        ML = (ll)maxx + rand() % maxx;
        MR = (ll)maxx + rand() % maxx;
    }
}Hash;


int main()
{
    int n, nc;
    scanf("%d%d", &n,&nc);

        scanf("%s", Hash.str);
        int m = strlen(Hash.str);
    //    cout << m << endl;
        Hash.init();
        Hash.Hash2(m);
        Hash.build();
        int cnt = 0;
        vector<ll> htable;
        for (int i = 0; i + n <= m; i++)
        {
            ll hh = Hash.get(i, i + n );
        //    cout << hh << endl;
        //    set<ll>::iterator it = htable.lower_bound(hh);
        //    if (it == htable.end() || *it != hh)
        //    {
            //    cnt++;
                htable.push_back(hh);
        //    }
        }
        sort(htable.begin(), htable.end());
        int ans = unique(htable.begin(), htable.end()) - htable.begin();
        printf("%d\n", ans);

}
