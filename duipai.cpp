
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstdio>
#include<cctype>
#include<sstream>
#include<string>
#include<cstring>
#include<deque>
#include<map>
#include<set>
#include<vector>
#include<list>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<fstream>
#define sf(a) scanf("%lf",&a)
#define sd1(a) scanf("%d",&a)
#define sd2(a,b) scanf("%d%d",&a,&b)
#define sd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sf(a) scanf("%lf",&a)
#define sf2(a,b) scanf("%lf%lf",&a,&b)
#define mp(a,b) make_pair(a,b)
using namespace std;
typedef long long ll;
ll n,k;
ll ans = 0;
void solve(int dep, ll remain, ll has, ll org){
    ll num = remain/has;
    ll re = remain%has;
    if(num&1){
        ans^=org;
        ans^=(org*k+1);
    }
    if(re){
        ans^=org;
        ans^=(org+re);
    }
    if(dep==1)return;
    solve(dep-1,remain,has*k,org*k+1);
}
int main(){
//    int pp = 0;
//    for(int i = 1; i <= 100; i++){
//        cout << (pp^i)<<endl;
//        pp^=i;
//    }
    int T;
    cin >> T;
    while(T--){
        ans = 0;
        cin >> n >> k;
        int h;
        ll remain = 0;
        ll all = 0,cur = 1;
        ll las = 0;
        for(int i = 0;; i++){
            if(all>n-cur){h = i;break;}
            all+=cur;
            las = cur;
            cur*=k;
        }
        remain = n - all;
        cur = 1;
        if(k&1){
            for(int i = 0; i < h; i++){
                ans^=cur;
                cur*=k;
                cur++;
            }
        }else{
            ans = all;
        }
        if(remain&1)ans^=1;
        solve(h,remain,k,1);
        printf("%lld\n",ans);
    }
    return 0;
}
