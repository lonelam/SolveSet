#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
int main()
{
    int l = 0, r = n;
    while(l < r) //跳出条件是要+1的。也就是l >= r的条件应该跳出！
    {
        const int mid = l + (r - l) / 2;//这句都是一样的，向下取整。
        if (val < arr[mid])//等于的情况是要放进l里面的，
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
}
