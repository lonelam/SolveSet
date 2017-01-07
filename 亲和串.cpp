#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 1000;

char s1[maxn];
char s2[maxn];
int nex[maxn];
void prekmp(int m)
{
    int i,j;
    j = nex[0] = -1;
    i = 0;
    while(i < m)
    {
        while(j != -1 && s2[i] != s2[j])j = nex[j];
        if (s2[++i] == s2[++j]) nex[i] = nex[j];
        else nex[i] = j;
    }
}
bool check()
{
    int n = strlen(s1);
    int m = strlen(s2);
    prekmp(m);
    int i, j;
    int ans = 0;
    i = j = 0;
    while(i < n)
    {
        while(-1 != j && s1[i] != s2[j]) j = nex[j];
        i++;j++;
        if (j >= m)
        {
            return true;
            j = nex[j];
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> s1 >> s2)
    {
        int n = strlen(s1);
        memcpy(s1 + n, s1, (n+ 1) * sizeof(char));
        //cout << s1 << endl;
        if (check())
        {
            cout <<"yes"<<endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
}
