#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  int h, w;
  cin >> h >> w;
  vector a(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];
  int ans = 0;
  rep(i, h) rep(j, w) ans = max(ans, a[i][j]);
  cout << ans << endl;
  return 0;
}
