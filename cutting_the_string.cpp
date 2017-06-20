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
const int MAXN = 10010;
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
        srand(12314);
        BL = (ll)maxx + rand() % maxx;
        BR = (ll)maxx + rand() % maxx;
        ML = (ll)maxx + rand() % maxx;
        MR = (ll)maxx + rand() % maxx;
    }
}Hash;
map<ll, vector<int> > mp[3005];
int main()
{
    scanf("%s", Hash.str);
    //for (int i = 0; i < 6000; i++) Hash.str[i] = 'a';
    //Hash.str[6000] = '\0';
    int n = strlen(Hash.str);
    Hash.init();
    Hash.Hash2(n);
    Hash.build();
    int ans = n * (n + 1) / 2;
    for (int len = 1; 2 * len <= n; len++)
    {
      for (int i = 0; i + len <= n; i++)
      {
        mp[len][Hash.get(i, i + len)].push_back(i);
      }
      for (int i = 0; i + 2 * len <= n; i++)
      {
        ll head = Hash.get(i, i + len);
        ll rear = Hash.get(i + len, i + len * 2);
        if (head == rear)
        {
          vector<int> & vv = mp[len][head];
          for (int j : vv)
          {
            if (j >= i + len && Hash.get(i + len, j + len) == Hash.get(i, j) || j < i && Hash.get(j, i + len) == Hash.get(j + len, i + 2 * len))
            {
              ans += 2;
            }
          }
        }
      }
    }
    printf("%d\n", ans);
}
