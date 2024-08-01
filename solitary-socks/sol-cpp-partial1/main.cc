#include <bits/stdc++.h>
using namespace std;

const int bit_size = 1000;
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
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

  vector<bitset<bit_size>> masks;
  for(int i = 0; i <= bit_size; i++) {
    bitset<bit_size> mask(0);
    for(int j = 0; j < i; j++) mask.set(j);
    masks.emplace_back(mask);
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
      queue<pair<int, bitset<bit_size>>> que;
      que.push({L, masks[0]});

      bool arrived = false;
      while(!que.empty()) {
        auto [now, bit] = que.front();
        que.pop();
        if(now == R) {
          cout << bit.count() << '\n';
          arrived = true;
          break;
        }
        if(visited[now]) continue;
        visited[now] = true;
        for(auto [to, nl, nr]: Graph[now]) {
          if(visited[to]) continue;
          que.push({to, bit ^ (masks[nl - 1] ^ masks[nr])});
        }
      }
      if(!arrived) cout << "Ambiguous\n";
    }
  }

  return 0;
}
