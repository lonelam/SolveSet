#include <bits/stdc++.h>
using namespace std;
const int maxn = 50000 + 100;
const int maxb = 300;
int bsize, bnum, n;
int L[maxb], R[maxb];
bool lazy[maxb];
int belong[maxn];
bool state[maxn];
void build()
{
  bsize = sqrt(n);
  bnum = n / bsize;
  if (n % bsize) bnum++;
  for (int i = 0; i < bnum; i++)
  {
    L[i] = i * bsize;
    R[i] = (i + 1) * bsize;
    lazy[i] = true;
  }
  R[bnum - 1] = n;
  for (int i = 0; i < n; i++)
  {
    belong[i] = i / bsize;
    state[i] = true;
  }
}

void destroy(int pos)
{
  lazy[belong[pos]] = false;
  state[pos] = false;
}

int query(int pos)
{
  if (!state[pos])
  {
    return 0;
  }
  int bl = belong[pos], br = belong[pos], l = pos, r = pos;
  if (lazy[belong[pos]])
  {
  //  cout <<"debuglazy\n";
    l = L[belong[pos]] - 1;
    r = R[belong[pos]];
  }
  for (; l >= L[belong[pos]]; l--)
  {
    if (!state[l])
    {
      break;
    }
  }
  if (l == L[belong[pos]] - 1)
  {
    while(l >= 0 && lazy[belong[l]])
    {
      l -= bsize;
    }
  }
  for (;l >= 0; l--)
  {
    if (!state[l])
    {
      break;
    }
  }
  for (;r < R[belong[pos]]; r++)
  {
    if (!state[r])
    {
      break;
    }
  }
  if (r == R[belong[pos]])
  {
    while(r < n && lazy[belong[r]])
    {
      r += bsize;
    }
  }
  for (; r < n; r++)
  {
    if (!state[r])
    {
      break;
    }
  }
  l = max(-1, l);
  r = min(r, n);
//  cout << l <<" "<< r << endl;
  return r - l - 1;
}

void recover(int pos)
{
  state[pos] = true;
  for (int i = L[belong[pos]];i < R[belong[pos]]; i++)
  {
    if (!state[i])
    {
      return;
    }
  }
  lazy[belong[pos]] = true;
}

int main()
{
  char cmd[100];
  int  m;
  while(cin >> n >> m)
  {
    build();
    stack<int> dset;
    int op;
    for (int i= 0; i < m; i++)
    {
      cin >> cmd;
      if (cmd[0] == 'D')
      {
        cin >> op;
        dset.push(op - 1);
        destroy(op - 1);
      }
      else if (cmd[0] == 'R')
      {
        recover(dset.top());
        dset.pop();
      }
      else if (cmd[0] == 'Q')
      {
        cin >> op;
        op--;
        cout << query(op)<< endl;
      }
    }
  }
}
