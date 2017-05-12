#include <bits/stdc++.h>
using namespace std;

const int MAXN = int( 2e5 );

int N, M, K;
int C[ MAXN ];
int liked[ MAXN ];

vector< int > cost[ 3 + 1 ];
vector< long long > pcost[ 3 + 1 ];

signed main() {
  ios::sync_with_stdio( 0 );
  cin >> N >> M >> K;
  for( int i = 0; i < N; ++i ) {
    cin >> C[ i ];
  }
  {
    int len;
    cin >> len;
    for( int i = 0; i < len; ++i ) {
      int v;
      cin >> v;
      liked[ v - 1 ] |= 1;
    }
    cin >> len;
    for( int i = 0; i < len; ++i ) {
      int v;
      cin >> v;
      liked[ v - 1 ] |= 2;
    }
  }
  for( int i = 0; i < N; ++i ) {
    cost[ liked[ i ] ].emplace_back( C[ i ] );
  }
  for( int i = 0; i <= 3; ++i ) {
    sort( cost[ i ].begin(), cost[ i ].end() );
    pcost[ i ].assign( cost[ i ].size() + 1, 0 );
    for( int j = 0; j < cost[ i ].size(); ++j ) {
      pcost[ i ][ j + 1 ] = pcost[ i ][ j ] + cost[ i ][ j ];
    }
  }
  long long ans = 1LL << 60;
  for( int t = 0; t <= cost[ 3 ].size(); ++t ) {
    if( t + min( cost[ 1 ].size(), cost[ 2 ].size() ) < K ) continue;
    if( t + cost[ 0 ].size() + cost[ 1 ].size() + cost[ 2 ].size() < M ) continue;
    int st = max( 0, K - t );
    if( t + st + st > M ) continue;
    int lb = 0, ub = int( 1e9 ); // lb not ok ub ok of max value taken
    while( lb + 1 != ub ) {
      int mid = lb + ub >> 1;
      int cnt = t;
      cnt += upper_bound( cost[ 0 ].begin(), cost[ 0 ].end(), mid ) - cost[ 0 ].begin();
      cnt += upper_bound( cost[ 1 ].begin() + st, cost[ 1 ].end(), mid ) - cost[ 1 ].begin();
      cnt += upper_bound( cost[ 2 ].begin() + st, cost[ 2 ].end(), mid ) - cost[ 2 ].begin();
      ( cnt >= M ? ub : lb ) = mid;
    }
    int cnt = t;
    long long tot = pcost[ 3 ][ t ];
    int f;
    f = upper_bound( cost[ 0 ].begin(), cost[ 0 ].end(), lb ) - cost[ 0 ].begin();
    cnt += f;
    tot += pcost[ 0 ][ f ];
    f = upper_bound( cost[ 1 ].begin() + st, cost[ 1 ].end(), lb ) - cost[ 1 ].begin();
    cnt += f;
    tot += pcost[ 1 ][ f ];
    f = upper_bound( cost[ 2 ].begin() + st, cost[ 2 ].end(), lb ) - cost[ 2 ].begin();
    cnt += f;
    tot += pcost[ 2 ][ f ];
    tot += 1LL * ( M - cnt ) * ub;
    ans = min( ans, tot );
  }
  if( ans == 1LL << 60 ) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
