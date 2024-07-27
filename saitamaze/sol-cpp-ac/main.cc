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
  if(0 <= x && x < h && 0 <= y && y < w) return false;
  return true;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll h, w;
  cin >> h >> w;
  vector x(h, vector<ll>(w));
  vector<ll> comp;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cin >> x[i][j];
      comp.emplace_back(x[i][j]);
    }
  }
  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());
  vector group(comp.size(), vector<P>{});
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      x[i][j] = lower_bound(comp.begin(), comp.end(), x[i][j]) - comp.begin();
      group[x[i][j]].emplace_back(P{i, j});
    }
  }

  vector dist(h, vector(w, INF));
  dist[0][0] = 0;
  priority_queue<T, vector<T>, greater<T>> pq;
  pq.push(T(0, 0, 0));
  while(!pq.empty()) {
    auto [d, i, j] = pq.top();
    pq.pop();
    if(dist[i][j] < d) continue;
    // 同じ高さのマスに移動
    for(auto [ni, nj]: group[x[i][j]]) {
      if(ni == i && nj == j) continue;
      if(dist[ni][nj] > d + abs(ni - i) + abs(nj - j) - 1) {
        dist[ni][nj] = d + abs(ni - i) + abs(nj - j) - 1;
        pq.push(T(dist[ni][nj], ni, nj));
      }
    }
    // 隣接マスに移動
    for(int dir = 0; dir < DIR_NUM; dir++) {
      ll ni = i + dx[dir], nj = j + dy[dir];
      if(outField(ni, nj, h, w)) continue;
      ll nd = d + 1;
      if(dist[ni][nj] > nd) {
        dist[ni][nj] = nd;
        pq.push(T(nd, ni, nj));
      }
    }
  }
  cout << dist[h - 1][w - 1] << endl;

  return 0;
}
