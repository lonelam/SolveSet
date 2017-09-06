typedef pair<int,int> PII;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 10010;
//ll gao[MAXN];
struct{
    ll BL,BR,ML,MR;
    ull psl[MAXN],psr[MAXN];
    char str[MAXN];
    ull hs[MAXN];
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
    void init(){
        int maxx = 1e9;
        srand(time(0));
        BL = (ll)maxx + rand() % maxx;
        BR = (ll)maxx + rand() % maxx;
        ML = (ll)maxx + rand() % maxx;
        MR = (ll)maxx + rand() % maxx;
    }
}Hash;
