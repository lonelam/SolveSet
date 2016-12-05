#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn];
int bs(int l, int r, int n, int T)
{
    if(l >= r)
    {
        return l;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    int midk = (l + r)/ 2;
    for(int i = 0; i< n; i++)
    {
        q.push(a[i]);
    }
    int cost = 0;
    //printf("%d %d\n",l, r);
    while(q.size() > 1)
    {
        int sum = 0;
        int tn = min(midk, (int)q.size());
        for(int i = 0; i < tn; i++)
        {
            sum += q.top();
           // cost += q.top();
            q.pop();
        }
        cost += sum;
        if(cost > T)
        {
            break;
        }
        q.push(sum);
    }
    if(cost == T)
    {
        return l;
    }
    else if(cost > T)
    {
        return bs(midk + 1, r, n, T);
    }
    else
    {
        return bs(l, midk, n, T);
    }

}

int main()
{
    int t, n, T;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d", &n, &T);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
        }

        printf("%d\n",bs(2, n, n, T));
    }
}
