#include <iostream>
#include <string.h>
#include <stdio.h>
using  namespace  std;

const int N=10010;
int a[N],m[N];

void extgcd(int a, int b, int &x, int &y)  {
  if(b == 0){
  	x = 1; y = 0;
    return;
  }
  extgcd(b, a % b, x, y);
  int tmp = x;
  x = y;
  y = tmp - (a / b) * y;
}

int CRT(int a[],int m[],int n){//x ≡ a[i] (mod m[i])
  int M = 1;
  int ans = 0;
  for(int i=1; i<=n; i++)
    M *= m[i];
  for(int i=1; i<=n; i++){
    int x, y;
    int Mi = M / m[i];
    extgcd(Mi, m[i], x, y); //Mi模mi的逆元
    ans = (ans + Mi * x * a[i]) % M;
  }
  if(ans < 0) ans += M;
  return ans;
}

int main(){
	int p,i,e,d,kase=1;
	while(cin>>p>>i>>e>>d){
		if(p==-1 && i==-1 && e==-1 && d==-1)break;
		a[1]=p;
		a[2]=i;
		a[3]=e;
		m[1]=23;
		m[2]=28;
		m[3]=33;
		int ans=CRT(a, m, 3);
		if(ans<=d)ans+=21252;
		printf("Case %d: the next triple peak occurs in %d days.\n", kase++, ans-d);
	}
	return 0;
}
