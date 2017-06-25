#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#define LL long long
using namespace std;
LL gcd(LL a,LL b){return !b?a:gcd(b,(a+b)%b);}
LL s1,s2,v1,v2,m;
void cgcd(LL a,LL b,LL &x,LL &y){
  if(!b){x=1,y=0;return;}
  cgcd(b,(a+b)%b,y,x),y-=x*(a/b);
}
int main(){
  scanf("%lld%lld%lld%lld%lld",&s1,&s2,&v1,&v2,&m);
  if(v1>v2)swap(s1,s2),swap(v1,v2);
  LL gg=gcd(v1-v2,m);if((s2-s1+gg)%gg!=0){printf("-1");return 0;}
  LL a=(v1-v2)/gg,b=m/gg;
  LL x,y;cgcd(a,b,x,y);
  x*=((s2-s1)/gg);
  while(x<0) x+=b;
  printf("%lld",x%b);
  return 0;
}
