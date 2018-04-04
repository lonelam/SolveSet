#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n;
const int N=(int)1e5+5;
char str[N];
struct Suffix_Automaton{
    static const int NODE=N<<1,C=26;
    int allc,lst,par[NODE],len[NODE],trans[NODE][C];
    int NewNode(){
        int ret=++allc;
        memset(trans[ret],0,C<<2);
        return ret;
    }
    int mem[NODE];
    void init(){
        allc=0;
        lst=NewNode();
        par[lst]=len[lst]=0;
        memset(mem, -1, sizeof(mem));
    }
    void extend(int c){
        int p=lst,np=NewNode();
        len[np]=len[lst]+1;
        for(;p&&!trans[p][c];p=par[p])trans[p][c]=np;
        if(!p)par[np]=1;
        else{
            int q=trans[p][c];
            if(len[q]==len[p]+1)par[np]=q;
            else{
                int nq=++allc;
                par[nq]=par[q];
                len[nq]=len[p]+1;
                memcpy(trans[nq],trans[q],C<<2);
                par[np]=par[q]=nq;
                for(trans[p][c]=nq,p=par[p];p&&trans[p][c]==q;p=par[p])trans[p][c]=nq;
            }
        }
        lst=np;
    }
    void cons(){
        init();
        int mmm = strlen(str);
        for (int i = 0; i < mmm; i++)
          extend(str[i]-'a');
    }
    int dfs(int u){
      if (mem[u] != -1) return mem[u];
      set<int> tmp;
      for (int c = 0; c < C; c++){
        if (trans[u][c]){
          tmp.insert(dfs(trans[u][c]));
        }
      }
      for (int i = 0; i <= C; i++){
        if (tmp.find(i) == tmp.end()) return mem[u] = i;
      }
      return mem[u] = 0;
    }
} sam;

int main(){
  while(~scanf("%s", str)){
    sam.cons();
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++){
      scanf("%s", str);
      int cur = 1;
      int mmm = strlen(str);
      for (int j = 0; j < mmm; j++){
        cur = sam.trans[cur][str[j] - 'a'];
      }
      // printf("%d\n", sam.dfs(cur));
      ans ^= sam.dfs(cur);
    }
    printf("%s\n", ans? "Alice": "Bob");

  }
}
