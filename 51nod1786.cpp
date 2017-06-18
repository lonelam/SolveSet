#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)>(y)?(y):(x))
#define INF 0x3f3f3f3f
#define MAXN 5000005

using namespace std;

int cnt=1,rt=0; //节点编号从1开始

struct Tree
{
    int key, pri, son[2]; //保证父亲的pri大于儿子的pri
    void set(int x, int y)
    {
        key=x;
        pri=y;
        son[0]=son[1]=0;
    }
}T[MAXN];

void rotate(int p, int &x)
{
    int y=T[x].son[!p];
    T[x].son[!p]=T[y].son[p];
    T[y].son[p]=x;
    x=y;
}

void ins(int key, int pri, int &x)
{
    if(x == 0)
        T[x = cnt++].set(key, pri);
    else
    {
        int p=key < T[x].key;
        ins(key, pri, T[x].son[!p]);
        if(T[x].pri < T[T[x].son[!p]].pri || T[x].pri == T[T[x].son[!p]].pri && T[x].key > T[T[x].son[!p]].key)
            rotate(p, x);
    }
}

void del(int key, int &x) //删除值为key的节点
{
    if(T[x].key == key)
    {
        if(T[x].son[0] && T[x].son[1])
        {
            int p=T[T[x].son[0]].pri > T[T[x].son[1]].pri || T[T[x].son[0]].pri == T[T[x].son[1]].pri && T[T[x].son[0]].key < T[T[x].son[1]].key;
            rotate(p, x);
            del(key, T[x].son[p]);
        }
        else
        {
            if(!T[x].son[0])
                x=T[x].son[1];
            else
                x=T[x].son[0];
        }
    }
    else
    {
        int p=T[x].key > key;
        del(key, T[x].son[!p]);
    }
}

int find(int key, int &x)
{
    if (x == 0) return 0;
    if (key == T[x].key)
    {
      return T[x].pri;
    }
    else if (key > T[x].key)
    {
      return find(key, T[x].son[1]);
    }
    else return find(key, T[x].son[0]);
}

int n, k;
int cmd;
int user;
int read()
{
    char ch=' ';
    int ans=0;
    while(ch<'0' || ch>'9')
        ch=getchar();
    while(ch<='9' && ch>='0')
    {
        ans=ans*10+ch-'0';
        ch=getchar();
    }
    return ans;
}
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
 inline void out(int x)
 {
     if(x>9)
         out(x/10);
     putchar(x%10+'0');
 }
int main()
{
  queue<int> Q;
  //n = read();
  in(n);
  //k = read();
  in(k);
  //scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++)
  {
   // scanf("%d", &cmd);
    //cmd = read();
    in(cmd);
    if (cmd == 2)
    {
      //printf("%d\n", T[rt].key);
      out(T[rt].key);
      putchar('\n');
    }
    else if (cmd == 1)
    {
      //scanf("%d", &user);
      //user = read();
      in(user);
      Q.push(user);
      if (Q.size() > k)
      {
        int out = Q.front();
        Q.pop();
        if (out == user)
        {
          continue;
        }
        int pcnt = find(out, rt);
        del(out, rt);
        if (--pcnt)
        {
          ins(out, pcnt, rt);
        }
      }
      int pcnt = find(user, rt);
      if (pcnt)
      {
        del(user, rt);
      }
      ins(user, pcnt+ 1, rt);
    }
  }
}
