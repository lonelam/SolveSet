#include <bits/stdc++.h>
using namespace std;
const int maxn = 50000 +100;
typedef long long ll;
typedef long double ld;
ll n, k;
ll power_k[maxn];
ll tree_size[maxn];
// Function to calculate xor
ll computeXOR()
{
    // If n is a multiple of 4
    if (n % 4 == 0)
        return n;

    // If n%4 gives remainder 1
    if (n % 4 == 1)
        return 1;

    // If n%4 gives remainder 2
    if (n % 4 == 2)
        return n + 1;

    // If n%4 gives remainder 3
    return 0;
}
ll getd()
{
    power_k[0] = 1;
   // ll presum = 0;
    for (int i = 1; i < 100; i++)
    {
        power_k[i] = power_k[i-1] * k;
        tree_size[i] = tree_size[i-1] + power_k[i-1];

        //cout << i << "   "<< power_k[i] << "  "<< tree_size[i] << endl;
        if (power_k[i]/k != power_k[i-1])
        {
            return ++i;
        }
        if (tree_size[i] < 0 || tree_size[i] >= n)
        {
            //c//out << presum << endl;
            //cout << i << endl;
            return i;
        }
    }
}
ll p_x(ll base, ll index)
{
    if (index & 1) return base;
    return 0;

}
void solve()
{
    scanf("%lld%lld", &n, &k);
    if (k == 1)
    {
        printf("%lld\n", computeXOR());
        return;
    }
    ll d = getd();
    ll ans = 0;
    ll sum = n;
    for (int i = 0; i + 1< d; i++)
    {
        ll tot = power_k[i];
        //cout << tot << endl;
        ll rem = sum - tot * tree_size[d - i - 1];
        //cout << rem << endl;
        ll fullones;
        if (i + 2 <= d && power_k[d-i-1]/k != power_k[d-i-2]) fullones = 0;
        else fullones = rem / power_k[d - i - 1];
      //  cout << fullones <<endl;
        ll emptyones = tot - fullones;
        if (i + 2 <= d && power_k[d-i-1]/k != power_k[d-i-2] || rem % power_k[d - i - 1])
        {
            emptyones--;
            ans ^= (rem % power_k[d - i - 1] + tree_size[d - i - 1]);
        }
       // cout << tot << "  " << fullones << " "<< emptyones<<endl;
        ans ^= p_x(tree_size[d-i-1], emptyones);
        ans ^= p_x(tree_size[d-i], fullones);
        sum -= power_k[i];
    }
    ans ^= p_x(1 , n - tree_size[d - 1]);
    printf("%lld\n", ans);
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        solve();
    }
}
