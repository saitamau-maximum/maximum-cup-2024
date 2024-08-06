#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> c(n);
  rep(i, n) cin >> c[i];
  vector Graph(n, vector<pair<int, int>>(0));
  rep(_, m) {
    int u, v, h;
    cin >> u >> v >> h;
    Graph[u - 1].push_back({ v - 1, h });
  }

  vector<int> indeg(n, 0);
  rep(u, n) for (auto [v, _] : Graph[u]) indeg[v]++;
  queue<int> q;
  rep(u, n) if (indeg[u] == 0) q.push(u);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto [v, _] : Graph[u])
      if (--indeg[v] == 0) q.push(v);
  }
  bool isDag = true;
  rep(u, n) if (indeg[u] > 0) isDag = false;

  cout << (isDag ? 0 : -1) << endl;
  return 0;
}
