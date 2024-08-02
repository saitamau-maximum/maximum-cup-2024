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
  // そうではないときはハミング距離が答えとなる
  int cnt = 0;
  vector<int> v_0to0, v_0to1, v_1to0, v_1to1;
  rep(i, n) {
    if (alpha[i] == beta[i]) {
      if (alpha[i] == 0)
        v_0to0.push_back(i);
      else
        v_1to1.push_back(i);
    }
    if (alpha[i] != beta[i]) {
      if (alpha[i] == 0)
        v_0to1.push_back(i);
      else
        v_1to0.push_back(i);

      if (d.size(i) > 1) {
        cout << -1 << endl;
        return 0;
      }

      cnt++;
    }
  }

  if (v_0to0.size() == 0 && v_1to1.size() == 0 && v_0to1.size() == 1 && v_1to0.size() == 1) {
    cout << -1 << endl;
    return 0;
  }

  cout << cnt << endl;

  // ----- 構築 ----- //

  vector<pair<int, int>> ans;

  auto change0to1 = [&]() {
    assert(v_0to1.size() > 0);
    int v = v_0to1.back();
    v_0to1.pop_back();
    v_1to1.push_back(v);
    ans.push_back({ v, 1 });
  };

  auto change1to0 = [&]() {
    assert(v_1to0.size() > 0);
    int v = v_1to0.front();
    v_1to0.pop_back();
    v_0to0.push_back(v);
    ans.push_back({ v, 0 });
  };

  while (v_0to1.size() || v_1to0.size()) {
    if (v_0to0.size() == 0 && v_1to1.size() == 0) {
      assert(v_0to1.size() > 1 || v_1to0.size() > 1);
      if (v_0to1.size() > 1)
        change0to1();
      else
        change1to0();
    }
    else if (v_0to0.size() == 0) {
      assert(v_1to1.size() > 0);
      change1to0();
    }
    else if (v_1to1.size() == 0) {
      assert(v_0to0.size() > 0);
      change0to1();
    }
    else {
      assert(v_0to0.size() > 0);
      assert(v_1to1.size() > 0);
      if (v_0to1.size() > 0) change0to1();
      if (v_1to0.size() > 0) change1to0();
    }
  }

  for (auto [v, c] : ans) cout << v + 1 << " " << c << endl;

  return 0;
}
