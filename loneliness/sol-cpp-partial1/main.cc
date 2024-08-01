#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int q;
  cin >> q;
  vector<int> comp;
  vector<tuple<int, int, int, int, int>> query;
  for(int i = 0; i < q; i++) {
    int t, L, R, l = -1, r = -1;
    cin >> t >> L >> R;
    comp.emplace_back(L);
    comp.emplace_back(R);
    if(t == 1) cin >> l >> r;
    query.emplace_back(tuple(t, L, R, l, r));
  }
  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());
  for(auto& [t, L, R, l, r]: query) {
    L = lower_bound(comp.begin(), comp.end(), L) - comp.begin();
    R = lower_bound(comp.begin(), comp.end(), R) - comp.begin();
  }

  vector<vector<tuple<int, int, int>>> Graph(comp.size());
  for(auto& [t, L, R, l, r]: query) {
    if(t == 1) {
      Graph[L].emplace_back(R, l, r);
      Graph[R].emplace_back(L, l, r);
    }
    else {
      // 愚直に Graph 上を探索
      vector<bool> visited(comp.size(), false);
      queue<pair<int, ll>> que;
      que.push({L, 0});

      bool arrived = false;
      while(!que.empty()) {
        auto [now, bit] = que.front();
        que.pop();
        if(now == R) {
          cout << __builtin_popcountll(bit) << '\n';
          arrived = true;
          break;
        }
        if(visited[now]) continue;
        visited[now] = true;
        for(auto [to, nl, nr]: Graph[now]) {
          if(visited[to]) continue;
          que.push({to, bit ^ ((1LL << nr) - (1LL << (nl - 1)))});
        }
      }
      if(!arrived) cout << "Ambiguous\n";
    }
  }

  return 0;
}
