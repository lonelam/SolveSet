#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include <iostream>
#include<ctime>
#include<set>
#include <map>
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
        srand(time(0));
        BL = (ll)maxx + rand() % maxx;
        BR = (ll)maxx + rand() % maxx;
        ML = (ll)maxx + rand() % maxx;
        MR = (ll)maxx + rand() % maxx;
    }
}Hash;

int main()
{
    int M, L;
    while(cin >> M >> L)
    {
        cin >> Hash.str;
        Hash.init();
        int n = strlen(Hash.str);
        Hash.Hash2(n);
        Hash.build();
        int ans = 0;
        for (int i = 0;i < L; i++)
        {
            map<ll, int> cnt;
            for (int j = i; j < i + L * M; j+= L)
            {
                cnt[Hash.get(j, j + L)]++;
            }
            if (cnt.size() == M)
            {
                ans++;
            }
            for (int j = 1; i + j * L + L * M <= n; j++)
            {
                ll hhout = Hash.get(i + (j - 1) * L, i + j * L );
                ll hhin = Hash.get(i + (j + M - 1) * L , i + j * L + L *M );
                if (--cnt[hhout] == 0)
                {
                    cnt.erase(hhout);
                }
                cnt[hhin]++;
                if (cnt.size() == M)
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}
