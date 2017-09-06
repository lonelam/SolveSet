#include <bits/stdc++.h>
using namespace std;
int ab[130000];
int a[130000];
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        multiset<int> st;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", ab + i);
            st.insert(ab[i]);
        }
        int p = 0;
        while(!st.empty())
        {
            int t = *st.begin();
            st.erase(st.begin());
            for (int i = 0; i < p; i++)
            {
                st.erase(st.find(a[i] + t));
            }
            a[p++] = t;
        }
        printf("%d\n", p);
        for (int i = 0; i < p; i++)
        {
            printf("%d%c", a[i], (i == (p-1))?'\n':' ');
        }
    }

}
