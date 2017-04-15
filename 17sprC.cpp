#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int vis[maxn];
int main()
{

    int n;
    while(cin >> n)
    {
        set<int> nodes;
        for (int i = 1; i <= n; i++)
        {
            nodes.insert(i);
        }
        string line;
        while(n--)
        {
            cin >> line;
            if (line == "New")
            {
                cout << *nodes.begin() << endl;
                nodes.erase(nodes.begin());
            }
            else if (line == "Delete")
            {
                int id;
                cin >> id;
                if (nodes.find(id) != nodes.end())
                {
                    cout << "Failed\n";
                }
                else
                {
                    cout <<"Successful\n";
                    nodes.insert(id);
                }
            }

        }
    }
}
