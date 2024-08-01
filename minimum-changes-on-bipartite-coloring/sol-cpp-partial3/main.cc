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
  // 変化しない頂点が 0 かつ 変化する頂点が 1 ずつなら -1
  // そうではないときはハミング距離が答え
  int cnt = 0;
  int cnt_0to0 = 0, cnt_0to1 = 0, cnt_1to0 = 0, cnt_1to1 = 0;
  rep(i, n) {
    if (alpha[i] == beta[i]) {
      (alpha[i] == 0 ? cnt_0to0 : cnt_1to1)++;
    }
    if (alpha[i] != beta[i]) {
      (alpha[i] == 0 ? cnt_0to1 : cnt_1to0)++;
      if (d.size(i) > 1) {
        cout << -1 << endl;
        return 0;
      }
      cnt++;
    }
  }

  if (cnt_0to0 == 0 && cnt_1to1 == 0 && cnt_0to1 == 1 && cnt_1to0 == 1) {
    cout << -1 << endl;
    return 0;
  }

  cout << cnt << endl;
  return 0;
}
