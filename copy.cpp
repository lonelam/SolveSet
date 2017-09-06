#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<vector>
using namespace std;
#define debug printf
int T;
const int maxn=10;//2*1e5+100;
const int mod=2;
int a[maxn];
int ans[maxn];
int n,m;
void solve();
int getcnt(int x);
bitset<maxn> bs;
int main()
{
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}

void solve()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
//    debug("readover\n");
    memset(ans,0,sizeof(ans));
    int nowcnt=0;
    bs.reset();
    for(int i=1;i<=n;i++){
        debug("%d %d\n",i,nowcnt);
        bs=bs<<1;
        if(nowcnt==0){
            bs.set(0);
        }
        else{
            bs.reset(0);
        }

        nowcnt+=getcnt(m+i);
        nowcnt-=getcnt(i);
        cout<<bs.to_string()<<endl;
        for(int j=1;j<=i;j++){
            if(bs.test(j-1)){
                ans[i]^=a[j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d",ans[i]);
        if(i==n)    putchar('\n');
        else putchar(' ');
    }

}

int getcnt(int x)
{
    int res=0;
    while(x%2==0){
        x/=2;
        res++;
    }
    return res;

}
