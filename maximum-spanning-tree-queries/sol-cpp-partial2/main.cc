#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

#include "dsu.hpp"

inline ll solve(int n, vector<tuple<int, int, int>> edges) {
  sort(edges.begin(), edges.end(), [](auto a, auto b) {
    return get<2>(a) > get<2>(b);
  });
  atcoder::dsu d(n);
  ll ans = 0;
  for (auto [a, b, c] : edges) {
    if (!d.same(a - 1, b - 1)) {
      d.merge(a - 1, b - 1);
      ans += c;
    }
  }
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> edges(m);
  for (auto&& [a, b, c] : edges) cin >> a >> b >> c;

  {
    sort(edges.begin(), edges.end(), [](auto a, auto b) {
      return get<2>(a) > get<2>(b);
    });
    atcoder::dsu d(n);
    vector<tuple<int, int, int>> usedEdges(0);
    for (auto [a, b, c] : edges) {
      if (!d.same(a - 1, b - 1)) {
        d.merge(a - 1, b - 1);
        usedEdges.push_back({ a, b, c });
      }
    }
    edges = usedEdges;
  }

  int q;
  cin >> q;
  while (q--) {
    int x, y, z;
    cin >> x >> y >> z;
    edges.push_back({ x, y, z });
    cout << solve(n, edges) << endl;
    edges.pop_back();
  }
  return 0;
}
