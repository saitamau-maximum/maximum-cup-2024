#include <bits/stdc++.h>
using namespace std;
using ll     = long long;
using P      = pair<ll, ll>;
using T      = tuple<ll, ll, ll>;
const ll INF = ((1LL << 62) - (1LL << 31));

// right | down | left | up
#define DIR_NUM 4
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

inline bool outField(int x, int y, int h, int w) {
  return !(0 <= x && x < h && 0 <= y && y < w);
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll h, w;
  cin >> h >> w;
  vector<vector<ll>> x(h, vector<ll>(w));
  vector<ll> comp;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cin >> x[i][j];
      comp.emplace_back(x[i][j]);
    }
  }
  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());
  vector<vector<P>> group(comp.size());
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      x[i][j] = lower_bound(comp.begin(), comp.end(), x[i][j]) - comp.begin();
      group[x[i][j]].emplace_back(P{i, j});
    }
  }

  // 辺を列挙
  vector<vector<vector<T>>> edges(h, vector<vector<T>>(w));
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      // 同じ高さのマスに移動
      for(auto [ni, nj]: group[x[i][j]]) {
        if(ni == i && nj == j) continue;
        ll cost = abs(ni - i) + abs(nj - j) - 1;
        edges[i][j].emplace_back(cost, ni, nj);
      }
      // 隣接マスに移動
      for(int dir = 0; dir < DIR_NUM; dir++) {
        ll ni = i + dx[dir], nj = j + dy[dir];
        if(outField(ni, nj, h, w) || x[i][j] == x[ni][nj]) continue;
        // 隣接マスの高さが異なる場合のみ追加
        edges[i][j].emplace_back(1, ni, nj);
      }
    }
  }

  vector<vector<ll>> dist(h, vector<ll>(w, INF));
  dist[0][0] = 0;
  priority_queue<T, vector<T>, greater<T>> pq;
  pq.push(T(0, 0, 0));
  while(!pq.empty()) {
    auto [d, i, j] = pq.top();
    pq.pop();
    if(dist[i][j] < d) continue;
    if(i == h - 1 && j == w - 1) {
      cout << dist[h - 1][w - 1] << endl;
      return 0;
    }
    for(auto &&[cost, ni, nj]: edges[i][j]) {
      if(dist[ni][nj] <= d + cost) continue;
      dist[ni][nj] = d + cost;
      pq.push(T(dist[ni][nj], ni, nj));
    }
  }

  return 0;
}
