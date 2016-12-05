#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct table
{
    int from, to;
    bool operator<( table & rhs)
    {
        return from < rhs.from;
    }
};
const int maxn = 300;
table mov[maxn];
bool vis[maxn];
int main()
{
    int t;
    int n;
    int a, b;
    while(cin >> t)
    {
        while(t--)
        {
            cin >> n;
            for(int i = 0; i < n; i++)
            {
                cin >> a >> b;
                if(a > b)
                    swap(a, b);
                mov[i].from = (a+ 1)/2;
                mov[i].to = (b+1)/2;
            }
            sort(mov, mov + n);
            memset(vis, 0, sizeof(vis));
            int rmost = -1;
            int ans = 0;
            int cnt = n;
            while(cnt)
            {
                ans++;
                for(int i = 0; i < n; i++)
                {
                    if(!vis[i] && mov[i].from > rmost)
                    {
                        vis[i] = true;
                        rmost = mov[i].to;
                        cnt--;
                    }
                }
                rmost = 0;
              //  cout<<"debug"<<endl;
            }
            cout<<ans * 10<<endl;
        }
    }
}
