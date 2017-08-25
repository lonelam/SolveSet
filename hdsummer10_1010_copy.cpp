#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
#define MAXN (100000 + 10)
#define INF (0x3f3f3f3f3f3f3f3f)
using namespace std;

struct edge{
    int to;
    ll cost;
    edge(int tv = 0, ll tc = 0):
        to(tv), cost(tc){}
};
typedef pair<ll ,int> P;
int N, R;
vector<edge> graph[MAXN];
ll dist[MAXN];     //最短距离
ll dist2[MAXN];    //次短距离
const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf+1;
inline void rnext()
{
    if(++ps == pe)
        pe = (ps = buf)+fread(buf,sizeof(char),sizeof(buf)/sizeof(char),stdin);
}
template <class T>
inline bool in(T &ans)
{
    ans = 0;
    T f = 1;
    if(ps == pe) return false;//EOF
    do{
        rnext();
        if('-' == *ps) f = -1;
    }while(!isdigit(*ps) && ps != pe);
    if(ps == pe) return false;//EOF
    do
    {
        ans = (ans<<1)+(ans<<3)+*ps-48;
        rnext();
    }while(isdigit(*ps) && ps != pe);
    ans *= f;
    return true;
}


const int  MAXOUT=10000;
char bufout[MAXOUT], outtmp[50],*pout = bufout, *pend = bufout+MAXOUT;
inline void write()
{
    fwrite(bufout,sizeof(char),pout-bufout,stdout);
    pout = bufout;
}
inline void out_char(char c){ *(pout++) = c;if(pout == pend) write();}
inline void out_str(char *s)
{
    while(*s)
    {
        *(pout++) = *(s++);
        if(pout == pend) write();
    }
}
template <class T>
inline void out_int(T x) {
    if(!x)
    {
        out_char('0');
        return;
    }
    if(x < 0) x = -x,out_char('-');
    int len = 0;
    while(x)
    {
        outtmp[len++] = x%10+48;
        x /= 10;
    }
    outtmp[len] = 0;
    for(int i = 0, j = len-1; i < j; i++,j--) swap(outtmp[i],outtmp[j]);
    out_str(outtmp);
}
void solve(){
    fill(dist, dist+N, INF);
    fill(dist2, dist2+N, INF);
    //从小到大的优先队列
    //使用pair而不用edge结构体
    //是因为这样我们不需要重载运算符
    //pair是以first为主关键字进行排序
    priority_queue<P, vector<P>, greater<P> > Q;
    //初始化源点信息
    dist[0] = 0;
    Q.push(P(0, 0));
    //同时求解最短路和次短路
    while(!Q.empty()){
        P p = Q.top(); Q.pop();
        //first为s->to的距离，second为edge结构体的to
        int v = p.second;
        ll d = p.first;
        //当取出的值不是当前最短距离或次短距离，就舍弃他
        if(dist2[v] < d) continue;
        for(unsigned i = 0; i < graph[v].size(); i++){
            edge &e = graph[v][i];
            ll d2 = d + e.cost;
            if(dist[e.to] > d2){
                swap(dist[e.to], d2);
                Q.push(P(dist[e.to], e.to));
            }
            if(dist2[e.to] > d2 && dist[v] < d2){
                dist2[e.to] = d2;
                Q.push(P(dist2[e.to], e.to));
            }
        }
    }
    printf("%lld\n", dist2[N-1]);
}

void tes(){
    int A, B;
    ll D;
    in(N);
    in(R);
    for(int i = 0; i < R; i++){
      in(A);
      in(B);
      in(D);
        graph[A-1].push_back(edge(B-1, D));
        graph[B-1].push_back(edge(A-1, D));
    }
    solve();
}
int main()
{
  freopen("data.in", "r", stdin);
  int T;
  in(T);
  while(T--)
  {
    tes();
  }
}
