#include<cstdio>
typedef long long ll;
ll x,y,e,p,q,P;int T,n,i;
ll exgcd(ll a,ll b){
  if(!b)return x=1,y=0,a;
  ll d=exgcd(b,a%b),t=x;
  return x=y,y=t-a/b*y,d;
}
ll rev(ll a,ll P){
  exgcd(a,P);
  while(x<0)x+=P;
  return x%P;
}
ll mul(ll a,ll b){
  ll t=0;
  for(;b;b>>=1,a=(a+a)%P)if(b&1)t=(t+a)%P;
  return t;
}
ll po(ll a,ll b){
  ll t=1;
  for(;b;b>>=1,a=mul(a,a))if(b&1)t=mul(t,a);
  return t;
}
int main(){
  scanf("%d",&T);
  while(T--){
    scanf("%lld%lld%lld%d",&e,&p,&q,&n);
    e=rev(e,(p-1)*(q-1));
    P=p*q;
    for(i=1;i<=n;i++){
      scanf("%lld",&x);
      printf("%lld%c",po(x,e),i<n?' ':'\n');
    }
  }
}
