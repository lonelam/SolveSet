#include <bits/stdc++.h>
using namespace std;
int n;
int a[100];
bool via[100];

int main()
{
  char name[100];
  cin >> name;
  FILE * tmp = stdin;
  while(freopen(name, "r", stdin) == NULL)
  {
    cout << "debug"<< endl;
    freopen("CON", "r", stdin);
    cin >> name;
  }
  cout << "ok "<<endl;
}
