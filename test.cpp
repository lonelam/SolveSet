#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int inf = 0x3f3f3f3f;
const int maxn = 100000;
void test(int *a)
{
  a[0] = a[1] = 100412;
}
int main()
{
  int a[100][2];
  cout << sizeof(a)/sizeof(int) << endl;
  cout << a[0][1] << " "<< a[0][0] << endl;
  cout << (a+1) << " "<< a << endl;
}
