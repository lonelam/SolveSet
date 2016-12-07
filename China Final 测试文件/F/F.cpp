#include<bits/stdc++.h>
using namespace std;

const int maxn = 400005;
char s[400005];
int A[maxn],G[maxn],T[maxn],C[maxn];

void init()
{
	int L = strlen(s);
	memset(A,0,sizeof(A));
	memset(G,0,sizeof(G));
	memset(T,0,sizeof(T));
	memset(C,0,sizeof(C));
	if(s[0] == 'A')A[0] = 1;
	if(s[0] == 'G')G[0] = 1;
	if(s[0] == 'T')T[0] = 1;
	if(s[0] == 'C')C[0] = 1;
	
	for(int i=1;i<L;++i){
		if(s[i] == 'A')A[i] = A[i-1] + 1;
		else A[i] = A[i-1];
		if(s[i] == 'G')G[i] = G[i-1] + 1;
		else G[i] = G[i-1];
		if(s[i] == 'T')T[i] = T[i-1] + 1;
		else T[i] = T[i-1];
		if(s[i] == 'C')C[i] = C[i-1] + 1;
		else C[i] = C[i-1];	
	}
	//for(int i=0;i<L;++i)cout<<A[i]<<' ';cout<<endl;
}

bool judge(int len)
{
	int L = strlen(s);
	int e = L/4;
	int flag = 0;
	for(int i=0;i<L-len;++i){
		int numA,numC,numG,numT;
		if(i>0){
			numA = A[i-1]+(A[L-1] - A[i+len-1]);
			numC = C[i-1]+(C[L-1] - C[i+len-1]);
			numG = G[i-1]+(G[L-1] - G[i+len-1]);
			numT = T[i-1]+(T[L-1] - T[i+len-1]);
		}
		else {
			numA = (A[L-1] - A[i+len-1]);
			numC = (C[L-1] - C[i+len-1]);
			numG = (G[L-1] - G[i+len-1]);
			numT = (T[L-1] - T[i+len-1]);
		}
		//cout<<A[L]<<' '<<A[i+len-1]<<endl;
		//cout<<i<<' '<<len<<numA<<' '<<numC<<' '<<numG<<' '<<numT<<endl;
		if(numA > e || numC > e || numG > e || numT > e)continue;
		else flag = 1;
	}
	return flag;
}

int main()
{

	int t;
	scanf("%d",&t);
	//cin>>t;
	while(t--){
		scanf("%s",s);
		init();
		int l = 0, r = strlen(s);
		int ans = r;
		while(l<=r){
			int mid = (l+r)/2;
			//cout<<l<<' '<<r<<' '<<mid<<endl; 
			if(judge(mid)){
				ans = min(ans,mid);
				r = mid - 1;
			}
			else l = mid + 1;
		}
		cout<<ans<<endl;	
	}
	return 0;
}
