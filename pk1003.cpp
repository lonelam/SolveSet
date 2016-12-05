#include <iostream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>L;X--)
#define DEP2(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)
const int maxn=505;


char s[maxn];
string str[maxn];
string ansa,ansb;
map<pair<string,string>,int> m;
int flag[maxn];
char aa[maxn],bb[maxn];


int main(){
	ios::sync_with_stdio(false);
	while(gets(s))
	{
		if(strcmp(s,"####")==0){
			map<pair<string,string>,int> :: iterator it;
			int mx=0;
			for(it=m.begin() ;it!=m.end() ;it++){
				//cout<<it->first.first<<' '<<it->first.second<<' '<<it->second<<endl;
				int num=it->second;
				if(num>mx){
					mx=num;
					ansa=it->first.first;
					ansb=it->first.second;
				}
			}
			ansa.copy(aa,ansa.length() ,0);*(aa+ansa.length())='\0';
			ansb.copy(bb,ansb.length() ,0);*(bb+ansb.length())='\0';
			printf("%s %s:%d\n",aa,bb,mx);
		//	cout<<ansa<<' '<<ansb<<":"<<mx<<endl;
			m.clear();
		}
		else{
			CLR(flag,0);
			//CLR(str,0);
			string a;
			int i=0,f=0,ff=0,len=strlen(s),tot=0;
			while(!islower(s[i]) && i<len) i++;
			while(i<len){
				while(islower(s[i])){
					f=1;a += s[i++];
				}
				if(f){
					str[tot++]=a;
					a.clear();
					f=0;
				}
				while(s[i]==' ') i++;
				while(s[i]==','||s[i]=='.') ff=1,i++;
				if(ff && islower(s[i])) {
					flag[tot-1]=1;
					ff=0;
				}
			}
			//REP(i,tot) cout<<flag[i]<<' ';cout<<endl;
			for(int i=0;i<tot-1;i++){
				if(!flag[i]) {
				//	cout<<str[i]<<' '<<str[i+1]<<endl;
					m[(make_pair(str[i],str[i+1]))]++;
				}
			}
		}
	}



	return  0;
}
/*
above,all ,above all good at good at good
at good at above all me this is
####
world hello ok www
####

, a , ,,, a a, . a.a a , ,   , .a  , , , , . . . a.
####
*/
