#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> c(n);
  rep(i, n) cin >> c[i];
  vector edges(m, tuple<int, int, int>());
  vector Graph(n, vector<pair<int, int>>(0));
  vector revGraph(n, vector<pair<int, int>>(0));
  rep(i, m) {
    int u, v, h;
    cin >> u >> v >> h;
    Graph[u - 1].push_back({ v - 1, i });
    revGraph[v - 1].push_back({ u - 1, i });
    edges[i] = { u - 1, v - 1, h };
  }

  vector<int> topological(0);
  vector<int> indeg(n, 0);
  rep(u, n) for (auto [v, _] : Graph[u]) indeg[v]++;
  queue<int> q;
  rep(u, n) if (indeg[u] == 0) q.push(u);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    topological.push_back(u);
    for (auto [v, _] : Graph[u])
      if (--indeg[v] == 0) q.push(v);
  }
  bool isDag = true;
  rep(u, n) if (indeg[u] > 0) isDag = false;

  if (!isDag) {
    cout << -1 << endl;
    return 0;
  }

  vector<ll> ans(m, 0);
  for (int i = n - 1; i >= 0; --i) {
    int v = topological[i];
    assert(revGraph[v].size() <= 1);
    if (revGraph[v].empty()) continue;
    int e = revGraph[v][0].second;
    ans[e] = c[v];
    for (auto [_, j] : Graph[v]) ans[e] += ans[j];
  }

  ll ansval = 0;
  for (int i = 0; i < m; ++i) ansval += ans[i] * get<2>(edges[i]);

  cout << ansval << endl;
  return 0;
}
