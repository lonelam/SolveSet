#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 5;
map <string, int> userid;
string username[maxn];
int  pre[maxn][maxn];
bool valid[maxn][maxn];
int colonpos[maxn];
//int preid = 0;
int n, m;

char to_space(char x)
{
    if (x == '.' || x == ',' || x == '!' || x == '?')
    {
        return ' ';
    }
    return x;
}
string chats[maxn];
string orig[maxn];
set<int> G[maxn];
int main()
{
    int T;
    int n;
    int m;
    string line;
    while(getline(cin, line))
    {
        stringstream Tin(line);
        Tin >> T;
        while(T--)
        {
            getline(cin,line);
            stringstream nin(line);
            nin >> n;
            getline(cin, line);
            stringstream userin(line);
            string user;
            userid.clear();
            for (int i = 0; i < n; i++)
            {
                userin >> user;
                userid[user] = i;
                username[i] = user;
            }
            getline(cin, line);
            stringstream mmin(line);
            mmin >> m;
            for (int i = 0; i < m; i++)
            {
                getline(cin, chats[i]);
                orig[i] = chats[i];
        //        colonpos[i] = find(chats[i].begin(), chats[i].end(), ':');
                for (int j = 0; j < chats[i].size(); j++)
                {
                    if (chats[i][j] == ':')
                    {
                        colonpos[i] = j;
                        break;
                    }
                }
                G[i].clear();
                chats[i][colonpos[i]] = ' ';
                for (int j = colonpos[i]; j < chats[i].size(); j++)
                {
                    chats[i][j] = to_space(chats[i][j]);
                }
            //    transform(chats[i].begin() + colonpos[i], chats[i].end(), to_space);
                stringstream luckyin(chats[i]);
                string speaker;
                luckyin >> speaker;
        //        cout << speaker << endl;
                if (speaker != "?")
                    G[i].insert(userid[speaker]);
                else
                {
                    for (int j = 0; j < n; j++)
                    {
                        G[i].insert(j);
                    }
                    string blocker;
                    while(luckyin >> blocker)
                    {
                        if (userid.find(blocker) != userid.end())
                            G[i].erase(userid[blocker]);
                    }
                }
            }
            memset(pre, -1, sizeof(pre));
            memset(valid, 0, sizeof(valid));
            for (int i = 0; i < m; i++)
            {
                for (int v : G[i])
                {
                    valid[i][v] = true;
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (valid[0][i])
                {
                    pre[0][i] = -2;
                }
            }
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (pre[i][j] != -1)
                    {
                        for (int k = 0; k < n; k++)
                        {
                            if (valid[i + 1][k] && k != j && pre[i+1][k] == -1)
                            {
                                pre[i + 1][k] = j;
                            }
                        }
                    }
                }
            }
  /*          for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << valid[i][j]<<" ";
                }
                cout << endl;
            }

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << pre[i][j]<<" ";
                }
                cout << endl;
            }*/
            bool ok = false;
            for(int i = 0; i < n; i++)
            {
                if (pre[m - 1][i] != -1)
                {
                    for (int j = m - 1; j >= 0; j--)
                    {
                        orig[j] = username[i] + orig[j].substr(colonpos[j], orig[j].length() - colonpos[j]);
                        i = pre[j][i];
                    }
                    ok = true;
                    break;
                }
            }
            if (ok)
            for (int i = 0; i < m; i++)
            {
                cout << orig[i] << endl;
            }
            else
            {
                cout <<"Impossible\n";
            }
        }
    }
}
