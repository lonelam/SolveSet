#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
int Comp[51][51];
void init() {
    for (int i = 0; i < 32; i++) {
        Comp[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            Comp[i][j] = Comp[i - 1][j - 1] + Comp[i - 1][j];
        }
    }
}

int d[51];
// returns how many numbers have K significant digits less or equal xx;
int Query(int xx, int K) {
    unsigned x = xx;
    int d[50] = {}, len = 0;
    int ans = 0, cnt = K;
    while (x) {
        d[++len] = x & 1;
        x >>= 1;
    }
    for (int i = len; i >= 1; i--) {
        if (d[i]) {
            ans += Comp[cnt][i - 1];
            cnt--;
        }
    }
    if (cnt == 0) ans++;
    return ans;
}
// return the smallest number which have R numbers between L and itself,
// including itselt,
// the returned number is exactly the Rth number having S significant digits
int bs(int l, int r, int R, int S) {
    int mid, c, L = l;
    int LQ = Query(L - 1, S);
    while (l < r) {
        mid = (ll)l + ((ll)r - l) / 2;
        c = Query(mid, S) - LQ;
        if (c >= R)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
int bucket[50];
int work(int l, int r, int k) {
    for (int i = 0; i < 32; i++) {
        if (l == 0) {
            bucket[i] = Query(r, i);
        } else
            bucket[i] = Query(r, i) - Query(l - 1, i);
    }
    int sum = 0;
    int i;
    for (i = 0; i < 32; i++) {
        if (sum + bucket[i] >= k) {
            break;
        }
        sum += bucket[i];
    }
    k -= sum;
    return bs(l, r, k, i);
}
int main() {
    int T = 1;
    int l, r, k;
    scanf("%d", &T);
    while (T--) {
        cin >> l >> r >> k;
        printf("%d\n", work(l, r, k));
    }
}
