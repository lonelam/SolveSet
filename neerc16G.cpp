

#include <bits/stdc++.h>
using namespace std;
int n;
void dfs(int i)
{
    for (int j = n - 1; j > i; j--)
    {
        cout << (j + 1) <<" "<< (j + 1) << " " << (i +1) << endl;
        if (j != i + 1) cout << (i + 1) << " "<< (i + 1) << " " << (j + 1) << endl;
    }
    if (i == n-1) return;
    dfs(i + 1);
    cout << (i + 1) << " " <<(i + 1) << " "<<(i + 2) << endl;
}
int main()
{
    while(cin >> n)
    {
        cout << "1 1 0" << endl;
        for (int j = n - 1; j > 0; j--)
        {
            cout << (j + 1) <<" "<< (j + 1) << " " << (1) << endl;
            if (j != 1) cout << 1<< " "<< ( 1) << " " << (j + 1) << endl;
        }
        dfs(1);
        cout << "0 1 2" << endl;
    }
}
