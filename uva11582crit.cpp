#include<cstdio>
#include<vector>
using namespace std;
typedef unsigned long long LLU;
const int maxn=1010;
vector<int> f[maxn];
void init(){
    for(int i=2;i<maxn;++i){
        f[i].push_back(0);
        f[i].push_back(1%i);
        for(int j=2;;++j){
            f[i].push_back((f[i][j-1]+f[i][j-2])%i);
            if(f[i][j-1]==0&&f[i][j]==1) break;
        }
        f[i].pop_back(),f[i].pop_back();
    }
    return;
}
LLU modexp(LLU a,LLU b,LLU mod){
    LLU cur=1,tmp=a;
    while(b){
        if(b&1) cur=cur*tmp%mod;
        tmp=tmp*tmp%mod;
        b>>=1;
    }
    return cur;
}
int main(){
    init();
    int t;scanf("%d",&t);
    while(t--){
        LLU a,b,n;
        scanf("%llu%llu%llu",&a,&b,&n);
        LLU k=LLU(f[n].size());
        printf("%d\n",k?f[n][modexp(a%k,b,k)]:0);
    }
    return 0;
}
