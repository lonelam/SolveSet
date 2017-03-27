    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef long double ld;
    const int inf = 0x3f3f3f3f;
    const int maxn = 100000;

    int main()
    {
        map<string, int> cnt;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            cnt[s]++;
        }
        int ans = cnt["Tetrahedron"] * 4 + cnt["Cube"] * 6 + cnt["Octahedron"] * 8 + cnt["Dodecahedron"] * 12 + cnt["Icosahedron"] * 20;
        cout <<ans << endl;
    }
