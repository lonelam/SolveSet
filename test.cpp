#include <bits/stdc++.h>
using namespace std;
int n;
int a[100];
bool via[100];

int main()
{
  a[0] = 0;
  for (int i = 1; i <= 20; i++)
  {
    a[i] = a[i-1] + i + (1 << i);
    cout << a[i] << endl;
  }
}
