#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <random>
using namespace std;
typedef long long ll;
typedef long double ld;
std::mt19937 rng_engine{(size_t)(new char)};
std::uniform_int_distribution<int> dist{1, 1000};
int main()
{
  int x, y, z;
  for (int i = 0; i < 10; i++)
  {
    cout << dist(rng_engine) << endl;
  }
}
