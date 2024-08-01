#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  int n, m;
  cin >> n >> m;
  vector BaseGraph(n, vector<int>(0));
  rep(_, m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    BaseGraph[u].push_back(v);
    BaseGraph[v].push_back(u);
  }
  vector<int> alphaVec(n), betaVec(n);
  rep(i, n) cin >> alphaVec[i];
  rep(i, n) cin >> betaVec[i];
  int alpha = 0, beta = 0;
  rep(i, n) {
    alpha += alphaVec[i] << i;
    beta += betaVec[i] << i;
  }

  // グラフ構築
  vector Graph(1 << n, vector<int>(0));
  vector<int> goodColoring;
  rep(S, 1 << n) {
    // 良い彩色かチェック
    if (S == 0 || S == (1 << n) - 1) continue;
    bool ok = true;
    rep(i, n) {
      for (int j : BaseGraph[i])
        if ((S >> i & 1) == (S >> j & 1)) ok = false;
    }
    if (ok) goodColoring.push_back(S);
  }
  rep(x, goodColoring.size()) {
    int S = goodColoring[x];
    for (int y = x + 1; y < goodColoring.size(); y++) {
      int T = goodColoring[y];
      if (popcount(unsigned(S ^ T)) == 1) {
        Graph[S].push_back(T);
        Graph[T].push_back(S);
      }
    }
  }

  // 復元付き BFS
  constexpr int INF = 1e9;
  vector<int> dist(1 << n, INF);
  vector<int> prev(1 << n, -1);
  queue<int> q;
  dist[alpha] = 0;
  q.push(alpha);
  while (!q.empty()) {
    int S = q.front();
    q.pop();
    for (int T : Graph[S]) {
      if (dist[T] == INF) {
        dist[T] = dist[S] + 1;
        prev[T] = S;
        q.push(T);
      }
    }
  }
  if (dist[beta] == INF) {
    cout << -1 << endl;
    return 0;
  }
  cout << dist[beta] << endl;
  vector<pair<int, int>> ops;
  for (int S = beta; S != alpha; S = prev[S]) {
    int T = prev[S];
    int i = countr_zero(unsigned(S ^ T));
    ops.push_back({ i, S >> i & 1 });
  }
  reverse(ops.begin(), ops.end());
  for (auto [i, c] : ops) cout << i + 1 << ' ' << c << '\n';
  return 0;
}
