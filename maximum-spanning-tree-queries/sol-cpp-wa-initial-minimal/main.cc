#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

#include "dsu.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> edges(m);
  for (auto&& [a, b, c] : edges) cin >> a >> b >> c;

  int minimEdge = 1e9;
  ll ans = 0;

  sort(edges.begin(), edges.end(), [](auto a, auto b) {
    return get<2>(a) > get<2>(b);
  });
  atcoder::dsu d(n);
  for (auto [a, b, c] : edges) {
    if (!d.same(a - 1, b - 1)) {
      d.merge(a - 1, b - 1);
      ans += c;
      minimEdge = min(minimEdge, c);
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int x, y, z;
    cin >> x >> y >> z;
    if (minimEdge >= z) {
      cout << ans << endl;
    }
    else {
      cout << ans - minimEdge + z << endl;
    }
  }
  return 0;
}
