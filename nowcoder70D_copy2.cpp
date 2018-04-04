#include<bits/stdc++.h>
#define N 100005
#define P pair<int,int>
using namespace std;
typedef long long ll;
const int M=1e9+7;
const int inf=1e9+7;
int pre[15];
set<ll>s;
void dfs(ll x)
{
    if(s.find(x)!=s.end())return;
    if(x)s.insert(x);
    if(x>=1000000000)return;
    dfs(x*10+4);
    dfs(x*10+7);
}
int main()
{
    int n,k;
    dfs(0);
    pre[1]=1;
    for(int i=2;i<=13;i++)
        pre[i]=pre[i-1]*i;
    scanf("%d%d",&n,&k);
    k--;
    int p=lower_bound(pre,pre+14,k)-pre;
    if(p>n){
        printf("-1\n");
        return 0;
    }
    //printf("%d\n",p);
    int a[20];
    for(int i=1;i<=p;i++)
        a[i]=n-p+i;
    for(int i=1;k;i++){
        int j=k/pre[p-i];
        //printf("%d %d \n",i,j);
        for(;j;j--)
            swap(a[i+j-1],a[i+j]);
        k%=pre[p-i];
    }
    int ans=0;
    for(set<ll>::iterator it=s.begin();*it<=n-p+1;it++)
        ans++;
    //printf("%d\n",ans);
    for(int i=1;i<=p;i++){
        if(s.find(n-p+i)!=s.end()&&s.find(a[i])!=s.end())ans++;
        //printf("%d %d\n",n-p+i,a[i]);
    }
    printf("%d\n",ans);
    return 0;
}
