#include <bits/stdc++.h>
#include <iostream>
#include "testlib.h"

using namespace std;
using ll = long long;

const int bit_size = 1000;
struct weighted_dsu {
  public:
  weighted_dsu(): _n(0) {}
  explicit weighted_dsu(ll n): _n(n), parent_or_size(n, -1), diff_weight(n, 0) {}

  ll merge(ll a, ll b, bitset<bit_size> w) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);

    w ^= weight(a);
    w ^= weight(b);

    ll x = leader(a), y = leader(b);
    if(x == y) return x;
    if(-parent_or_size[x] < -parent_or_size[y]) swap(x, y);

    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;
    diff_weight[y]    = w;

    return x;
  }

  bool same(ll a, ll b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }

  ll leader(ll a) {
    assert(0 <= a && a < _n);
    if(parent_or_size[a] < 0) return a;
    ll r = leader(parent_or_size[a]);
    diff_weight[a] ^= diff_weight[parent_or_size[a]];
    return parent_or_size[a] = r;
  }

  bitset<bit_size> weight(ll x) {
    leader(x); // 経路圧縮
    return diff_weight[x];
  }

  bitset<bit_size> diff(ll x, ll y) {
    return weight(y) ^ weight(x);
  }

  private:
  ll _n;
  vector<ll> parent_or_size;
  vector<bitset<bit_size>> diff_weight;
};

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);

  int N = inf.readInt(1, 1'000, "N"); // 1 <= N <= 1000
  inf.readSpace();
  int Q = inf.readInt(1, 200'000, "Q"); // 1 <= Q <= 2 * 10^5
  inf.readEoln();                       // 改行

  vector<ll> comp;
  vector<tuple<int, int, int, int, int>> query;

  for(int i = 0; i < Q; i++) {
    int t = inf.readInt(1, 2, "t"); // 1 <= t <= 2
    inf.readSpace();
    int L = inf.readInt(1, 1'000'000'000, "L"); // 1 <= L < R <= 10^9
    inf.readSpace();
    int R = inf.readInt(L + 1, 1'000'000'000, "R"); // 1 <= L < R <= 10^9
    int l = -1, r = -1;
    if(t == 1) {
      inf.readSpace();
      l = inf.readInt(1, N, "l"); // 1 <= l <= r <= N
      inf.readSpace();
      r = inf.readInt(l, N, "r"); // 1 <= l <= r <= N
    }
    inf.readEoln(); // 改行

    comp.emplace_back(L);
    comp.emplace_back(R);
    query.emplace_back(t, L, R, l, r);
  }
  inf.readEof(); // EOF

  sort(comp.begin(), comp.end());
  comp.erase(unique(comp.begin(), comp.end()), comp.end());
  vector<bitset<bit_size>> masks;
  for(int i = 0; i <= bit_size; i++) {
    bitset<bit_size> mask;
    for(int j = 0; j < i; j++) mask.set(j);
    masks.emplace_back(mask);
  }

  // Query 1 の Validation
  int q2_cnt = 0;
  weighted_dsu uf(comp.size());
  for(auto [t, L, R, l, r]: query) {
    if(t == 2) {
      q2_cnt++;
      continue;
    }
    L = lower_bound(comp.begin(), comp.end(), L) - comp.begin();
    R = lower_bound(comp.begin(), comp.end(), R) - comp.begin();
    ensuref(!uf.same(L, R) || uf.diff(L, R) == (masks[l - 1] ^ masks[r]), "Invalid query %d %d %d %d %d\ndiff: %s", t, L, R, l, r, uf.diff(L, R).to_string().c_str());
    uf.merge(L, R, masks[l - 1] ^ masks[r]);
  }
  ensuref(q2_cnt != 0, "Query 2 is not found");

  return 0;
}
