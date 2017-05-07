  #include <bits/stdc++.h>
  using namespace std;
  typedef long long ll;
  typedef long double ld;
  const int inf = 0x3f3f3f3f;
  const int maxn = 100000 + 100;
  char s[maxn];
  bool vis[10000];
  int main()
  {
    int n;
    int kase = 1;
    while(scanf("%d", &n) != EOF)
    {
      for (int k = 1; k <= n; k++)
      {
        scanf("%s", s);
        int len = strlen(s);
        int ans = 0, l = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < len; i++)
        {
          vis[s[i] - 'a'] = true;
        }
        for (int i = 0; i < 26; i++)
        {
          if (vis[i]) ans++;
        }
        printf("Case #%d: %d\n",k, ans);
      }
    }
  }
