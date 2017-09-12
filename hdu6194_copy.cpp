#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

namespace suffixarray{
    #define FN(n) for(int i=0;i<n;i++)
    const int N =1E5+7;
    int rnk[N],sa[N],height[N],c[N];char s[N];
    void getsa(int n,int m,int *x=rnk,int *y=height){
        FN(m)c[i]=0;FN(n)c[x[i]=s[i]]++;FN(m)c[i+1]+=c[i];
        for(int i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
        for(int k=1,p;p=0,k<=n;k=p>=n?N:k<<1,m=p){
            for(int i=n-k;i<n;i++)y[p++]=i;
            FN(n)if(sa[i]>=k)y[p++]=sa[i]-k;
            FN(m)c[i]=0;FN(n)c[x[y[i]]]++;FN(m)c[i+1]+=c[i];
            for(int i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
            swap(x,y),p=1,x[sa[0]]=0;
            for(int i=1;i<n;i++)
            x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
        }
        FN(n)rnk[sa[i]]=i;
        for(int i=0,j,k=0;i<n-1;height[rnk[i++]]=k)
        for(k=k?k-1:k,j=sa[rnk[i]-1];s[i+k]==s[j+k];k++);
    }
}
using namespace suffixarray;

int t,k,n,f[N][20];

void rmq(int *a)
{
    for(int i=1;i<=n;i++)f[i][0]=a[i];
    for(int j=1;1<<j<n;j++)for(int i=1;i<=n;i++)
    if(i+(1<<j)-1<=n)f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
    else break;
}
inline int find(int l,int r)
{
    int k=31-__builtin_clz(r-l+1);
    return min(f[l][k],f[r-(1<<k)+1][k]);
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%s",&k,s);
        n=strlen(s),getsa(n+1,300);
        height[n+1]=0;rmq(height);
        int ans=0;
        F(i,1,n)
        {
            if(i+k-1>n)continue;
            int lcp;
            if(i+1>i+k-1) lcp=n-sa[i];
            else lcp=find(i+1,i+k-1);
            lcp-=max(height[i],height[i+k]);
            if(lcp<=0)continue;
            ans+=lcp;
        }
        printf("%d\n",ans);
    }
    return 0;
}
