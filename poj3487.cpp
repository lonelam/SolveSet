#include <bits/stdc++.h>
using namespace std;
map<char, vector<char> > G;
map<char, int> start;
map<char, char> pal;
map<char, map<char, int> > prior;
map<char, bool> vis;
int n;
int main()
{
    int T;
    while(scanf("%d", &T)!= EOF)
    {
        while(T--)
        {
            G.clear();
            pal.clear();
            scanf("%d", &n);
            char buffer[100];
            set<char> unvis;
            for (int i = 0; i < 2 * n; i++)
            {
                scanf("%s", buffer);
              //  unvis.insert(buffer[0]);
                if (islower(buffer[0]))
                {
                    start[buffer[0]] = 0;
                    unvis.insert(buffer[0]);
                }
            }
            for (int i = 0; i < 2 * n; i++)
            {
                scanf("%s", buffer);
                int m = strlen(buffer);
                for (int j = 2; j < m; j++)
                {
                    G[buffer[0]].push_back(buffer[j]);
                    prior[buffer[0]][buffer[j]] = m - j;
                }
            }

            while(!unvis.empty())
            {
                char cur = *unvis.begin();

               // unvis.erase(unvis.begin());
            //    cout << cur << endl;
                for (int & i = start[cur]; i < G[cur].size(); i++)
                {
                    char v = G[cur][i];
               //         cout << v << " "<< cur << endl;
                    if (!vis[v] || prior[v][pal[v]] < prior[v][cur])
                    {
                        if (!vis[v])
                        {
                            vis[v] = true;
                        }
                        else
                        {
                            unvis.insert(pal[v]);
                            vis[pal[v]] = false;
                        }
                        pal[v] = cur;
                        pal[cur] = v;
                        unvis.erase(cur);
                        break;
                    }

                }
                if (start[cur] == G[cur].size())
                {
                    unvis.erase(cur);
                }
            }
            for (map<char,char>::iterator i = pal.begin(); i != pal.end(); i++)
            {
                if (islower(i->first))
                {
                    printf("%c %c\n", i->first, i->second);
                }
            }
            if (T) printf("\n");
        }
    }
}
