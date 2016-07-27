#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 22;
bool nprime[2*maxn];
bool used[maxn];
int n;
int circle[maxn];
void dfs(int cur)
{
    if(cur == n)
    {
        if(!nprime[circle[n-1]+circle[0]])
        {
            bool started = false;
            for(int i=0;i<n;i++)
            {
                if(started)
                {
                    cout<<' '<<circle[i];
                }
                else
                {
                    started = true;
                    cout<<circle[i];
                }
            }
            cout<<endl;
        }
        return;
    }
    for(int i = 1;i <= n;i++)
    {
        if(!used[i] && !nprime[circle[cur-1]+i])
        {
            circle[cur]= i;
            used[i]= true;
            dfs(cur+1);
            used[i] = false;
        }
    }
}
int main()
{
    //init prime
    ios::sync_with_stdio(false);
    memset(nprime,0,sizeof(nprime));
    nprime[1] = true;
    nprime[0] = true;
    for(int i = 2;i<2*maxn;i++)
    {
        if(!nprime[i])
        {
            for(int j = i+i;j < 2* maxn;j+=i)
            {
                nprime[j] = true;
            }
        }
    }

    int kase = 1;

    while(cin>>n)
    {
        cout<<"Case "<<kase++<<":\n";
        circle[0] = 1;
        memset(used,0,sizeof(used));
        used[1] = true;
        dfs(1);
        cout<<endl;
    }
}
