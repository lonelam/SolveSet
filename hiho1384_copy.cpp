#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=500010,BUF=40000000;
char Buf[BUF],*buf=Buf;
int T,n,m,cnt,i,a[N],b[N];
ll limit,maxdiff;
inline bool cmp(int x,int y){return b[x]<b[y];}
inline void read(int&a){for(a=0;*buf<48;buf++);while(*buf>47)a=a*10+*buf++-48;}
inline void read(ll&a){for(a=0;*buf<48;buf++);while(*buf>47)a=a*10+*buf++-48;}
inline void cal(int l,int r){
  int i,j,n=0;
  for(i=l;i<=r;i++)a[n++]=b[i];
  maxdiff=0;
  sort(a,a+n);
  for(i=0,j=n-1;i<j&&i<m;i++,j--){
    maxdiff+=1LL*(a[i]-a[j])*(a[i]-a[j]);
    if(maxdiff>limit)break;
  }
}
inline void init(int l,int r){
  cnt=0;
  for(int i=l;i<=r;i++)a[cnt++]=i;
  sort(a,a+cnt,cmp);
}
inline void cal2(int r){
  int i,j,k;
  maxdiff=0;
  for(i=0,j=cnt-1,k=m;k;i++,j--,k--){
    while(i<j&&a[i]>r)i++;
    while(i<j&&a[j]>r)j--;
    if(i>=j)return;
    maxdiff+=1LL*(b[a[i]]-b[a[j]])*(b[a[i]]-b[a[j]]);
    if(maxdiff>limit)break;
  }
}
inline int solve(){
  int i,j,l,r,mid,t,now=0;
  for(i=1;i<=n;i=t+1){
    for(j=1;i+(1<<j)-1<=n;j++){
      cal(i,i+(1<<j)-1);
      if(maxdiff>limit)break;
    }
    t=i,l=i+(1<<(j-1))-1,r=i+(1<<j)-1;
    if(r>n)r=n;
    init(i,r);
    while(l<=r){
      cal2(mid=(l+r)>>1);
      if(maxdiff<=limit)l=(t=mid)+1;else r=mid-1;
    }
    now++;
  }
  return now;
}
int main(){
  fread(Buf,1,BUF,stdin);read(T);
  while(T--){
    read(n),read(m);
    read(limit);
    for(i=1;i<=n;i++)read(b[i]);
    printf("%d\n",solve());
  }
  return 0;
}
