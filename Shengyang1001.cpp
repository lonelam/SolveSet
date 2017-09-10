//qscqesze
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <queue>
#include <typeinfo>
#include <fstream>
#include <map>
#include <stack>
typedef long long ll;
using namespace std;
//freopen("D.in","r",stdin);
//freopen("D.out","w",stdout);
#define sspeed ios_base::sync_with_stdio(0);cin.tie(0)
#define maxn 1005000
#define mod 10007
#define eps 1e-9
int Num;
char CH[20];
//const int inf=0x7fffffff;   //нчоч╢С
const int inf=0x3f3f3f3f;
inline ll read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//**************************************************************************************

int s[2*maxn];
int a[maxn];
int n,k;
int sa[maxn], rank[maxn], height[maxn];
int wa[maxn], wb[maxn], wv[maxn], wd[maxn];

int cmp(int *r, int a, int b, int l){
    return r[a] == r[b] && r[a+l] == r[b+l];
}

void build_sa(int *r, int n, int m){          //  倍增算法 r为待匹配数组  n为总长度 m为字符范围
    int i, j, p, *x = wa, *y = wb, *t;
    for(i = 0; i < m; i ++) wd[i] = 0;
    for(i = 0; i < n; i ++) wd[x[i]=r[i]] ++;
    for(i = 1; i < m; i ++) wd[i] += wd[i-1];
    for(i = n-1; i >= 0; i --) sa[-- wd[x[i]]] = i;
    for(j = 1, p = 1; p < n; j *= 2, m = p){
        for(p = 0, i = n-j; i < n; i ++) y[p ++] = i;
        for(i = 0; i < n; i ++) if(sa[i] >= j) y[p ++] = sa[i] - j;
        for(i = 0; i < n; i ++) wv[i] = x[y[i]];
        for(i = 0; i < m; i ++) wd[i] = 0;
        for(i = 0; i < n; i ++) wd[wv[i]] ++;
        for(i = 1; i < m; i ++) wd[i] += wd[i-1];
        for(i = n-1; i >= 0; i --) sa[-- wd[wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i ++){
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p - 1: p ++;
        }
    }
}

void calHeight(int *r, int n){           //  求height数组。
    int i, j, k = 0;
    for(i = 1; i <= n; i ++) rank[sa[i]] = i;
    for(i = 0; i < n; height[rank[i ++]] = k){
        for(k ? k -- : 0, j = sa[rank[i]-1]; r[i+k] == r[j+k]; k ++);
    }
}
int check(int mid)
{
    int num=0;
    for(int i=0;i<n;i++)
    {
        if(height[i]>=mid)
            num++;
        else
            num=1;
        if(num>=k)
            return 1;
    }
    return 0;
}
int main()
{
    n=read(),k=read();
    for(int i=0;i<n;i++)
        a[i]=read(),a[i]++;
    a[n++]=0;
    build_sa(a,n,1001000);
    calHeight(a,n);
    int l=0,r=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            l=mid+1;
        }
        else
            r=mid-1;
    }
    cout<<r<<endl;
}
