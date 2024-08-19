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

  ll ans = 0;
  {
    sort(edges.begin(), edges.end(), [](auto a, auto b) {
      return get<2>(a) > get<2>(b);
    });
    atcoder::dsu d(n);
    vector<tuple<int, int, int>> usedEdges(0);
    for (auto [a, b, c] : edges) {
      if (!d.same(a - 1, b - 1)) {
        d.merge(a - 1, b - 1);
        ans += c;
        usedEdges.push_back({ a - 1, b - 1, c });
      }
    }
    edges = usedEdges;
  }

  vector Graph(n, vector<pair<int, int>>(0));
  for (auto [a, b, c] : edges) {
    Graph[a].push_back({ b, c });
    Graph[b].push_back({ a, c });
  }

  // 0 を根にする
  const int log2n = bit_width((unsigned int) n);
  vector<int> depth(n, -1);
  vector par(n, vector<int>(log2n, -1));
  vector minim(n, vector<int>(log2n, 2e9));

  // initialize
  {
    queue<int> q;
    q.push(0);
    depth[0] = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (auto [u, c] : Graph[v]) {
        if (depth[u] == -1) {
          depth[u] = depth[v] + 1;
          par[u][0] = v;
          minim[u][0] = c;
          q.push(u);
        }
      }
    }
    rep(k, log2n - 1) rep(v, n) {
      if (par[v][k] != -1) {
        par[v][k + 1] = par[par[v][k]][k];
        minim[v][k + 1] = min(minim[v][k], minim[par[v][k]][k]);
      }
    }
  }

  auto Query = [&](int x, int y) {
    if (depth[x] < depth[y]) swap(x, y);
    int res = 2e9;
    int t = depth[x] - depth[y];
    for (int k = log2n - 1; k >= 0; --k) {
      if (t & (1 << k)) {
        res = min(res, minim[x][k]);
        x = par[x][k];
      }
    }
    if (x == y) return res;
    for (int k = log2n - 1; k >= 0; --k) {
      if (par[x][k] != par[y][k]) {
        res = min({ res, minim[x][k], minim[y][k] });
        x = par[x][k], y = par[y][k];
      }
    }
    return min({ res, minim[x][0], minim[y][0] });
  };

  int q;
  cin >> q;
  while (q--) {
    int x, y, z;
    cin >> x >> y >> z;
    int res = Query(x - 1, y - 1);
    if (res >= z) {
      // z は不採用
      cout << ans << endl;
    }
    else {
      cout << ans - res + z << endl;
    }
  }
  return 0;
}
