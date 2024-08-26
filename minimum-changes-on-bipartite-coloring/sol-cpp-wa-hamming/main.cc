#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

#include "dsu.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector Graph(n, vector<int>(0));
  atcoder::dsu d(n);
  rep(_, m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    Graph[u].push_back(v);
    Graph[v].push_back(u);
    d.merge(u, v);
  }
  vector<int> alpha(n), beta(n);
  rep(i, n) cin >> alpha[i];
  rep(i, n) cin >> beta[i];

  // 2 頂点以上の連結成分が変更されていれば -1
  // そうではないときはハミング距離が答え (WA)
  int cnt = 0;
  rep(i, n) {
    if (alpha[i] != beta[i]) {
      if (d.size(i) > 1) {
        cout << -1 << endl;
        return 0;
      }
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
