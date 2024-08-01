#include <bits/stdc++.h>
using namespace std;

const int bit_size = 3000;
struct weighted_dsu {
  public:
  weighted_dsu(): _n(0) {}
  explicit weighted_dsu(int n): _n(n), parent_or_size(n, -1), diff_weight(n, 0) {}

  int merge(int a, int b, bitset<bit_size> w) {
    w ^= weight(a);
    w ^= weight(b);

    int x = leader(a), y = leader(b);
    if(x == y) return x;
    if(-parent_or_size[x] < -parent_or_size[y]) swap(x, y);

    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;
    diff_weight[y]    = w;

    return x;
  }

  bool same(int a, int b) {
    return leader(a) == leader(b);
  }

  int leader(int a) {
    if(parent_or_size[a] < 0) return a;
    int r = leader(parent_or_size[a]);
    diff_weight[a] ^= diff_weight[parent_or_size[a]];
    return parent_or_size[a] = r;
  }

  bitset<bit_size> weight(int x) {
    leader(x); // 経路圧縮
    return diff_weight[x];
  }

  bitset<bit_size> diff(int x, int y) {
    return weight(y) ^ weight(x);
  }

  private:
  int _n;
  vector<int> parent_or_size;
  vector<bitset<bit_size>> diff_weight;
};

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

  weighted_dsu uf(comp.size());
  for(auto& [t, L, R, l, r]: query) {
    if(t == 1) uf.merge(L, R, masks[l - 1] ^ masks[r]);
    else {
      if(!uf.same(L, R)) cout << "Ambiguous\n";
      else cout << uf.diff(L, R).count() << "\n";
    }
  }

  return 0;
}
