#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;

/*
基于HDOJ 2222 的 AC自动机
文本串对多个模板串的查找
*/

const int maxn=610000;
const int chsize = 26;
int ch[maxn][chsize],fail[maxn],flg[maxn], vis[maxn];
int root,sz;
char str[1000100];

int newnode()
{
	memset(ch[sz],-1,sizeof(ch[sz]));
	flg[sz++]=0;
	return sz-1;
}

void init()
{
	sz=0;
	root=newnode();
}

void insert(char str[])
{
	int len=strlen(str);
	int now=root;
	for(int i=0;i<len;i++)
	{
		int& temp=ch[now][str[i]-'a'];
		if(temp==-1) temp=newnode();
		now=temp;
	}
	flg[now]++;
}

void build()
{
	queue<int> q;
	fail[root]=root;

	for(int i=0;i<26;i++)
	{
		int& temp=ch[root][i];
		if(temp==-1) temp=root;
		else
		{
			fail[temp]=root;
			q.push(temp);
		}
	}
	while(!q.empty())
	{
		int now=q.front(); q.pop();
		//// 嵌套串
		if(flg[fail[now]]) flg[now]++;
		for(int i=0;i<chsize;i++)
		{
			if(ch[now][i]==-1)
				ch[now][i]=ch[fail[now]][i];
			else
			{
				fail[ch[now][i]]=ch[fail[now]][i];
				q.push(ch[now][i]);
			}
		}
	}
}

int query(char str[])
{
    int len=strlen(str);
    int now=root;
    int ret=0;
	memset(vis, 0,sizeof(vis));
    for(int i=0;i<len;i++)
    {
        now=ch[now][str[i]-'a'];
        int temp=now;
        while(temp!=root&&~flg[temp] && !vis[temp])
        {
            ret+=flg[temp];
			//one enough
            flg[temp]=-1;
			vis[temp] = 1;
            temp=fail[temp];
        }
    }
    return ret;
}
