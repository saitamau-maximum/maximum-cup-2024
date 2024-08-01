#include <bits/stdc++.h>
#include <vector>
#include "testlib.h"
using namespace std;

// ファイル名に含まれるかどうか
#define namecontains(t) (filename.find(t) != string::npos)

using ll           = long long;
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
  registerGen(argc, argv, 1);
  const string filename = argv[1];

  // 問題に応じた最大値や制約を設定
  constexpr long long MaxVal = 1'000'000'000; // 1e9
  constexpr int MaxN         = 1'000;         // 1000
  constexpr int MaxQ         = 200'000;       // 2e5
  constexpr int PartialQ     = 3000;          // 3000

  int n      = -1;
  int q      = -1;
  int lr_num = -1;

  int maxQ = MaxQ;
  if(namecontains("task1")) maxQ = PartialQ;

  if(namecontains("max")) {
    n      = MaxN;
    q      = maxQ;
    lr_num = rnd.next(10, 2 * q / 2);
  } else if(namecontains("min")) {
    n      = 1;
    q      = 1;
    println(n, q);
    println(2, 3141592, 31415926);
    return 0;
  } else {
    n      = rnd.next(1, MaxN); // 1 <= n <= 2e5
    q      = rnd.next(1, maxQ); // 1 <= q <= 2e5
    lr_num = rnd.next(10, 2 * q / 2);
  }

  vector<long long> lr;
  set<long long> st;
  for(int i = 0; i < maxQ * 2; i++) {
    ll r = rnd.next(1LL, MaxVal);
    while(st.count(r)) r = rnd.next(1LL, MaxVal);
    st.insert(r);
    lr.emplace_back(r);
  }
  sort(lr.begin(), lr.end());

  // 予め bit mask は作成しておく
  vector<bitset<bit_size>> masks;
  for(int i = 1; i <= bit_size; i++) {
    bitset<bit_size> mask;
    for(int j = 0; j < i; j++) mask.set(j);
    masks.emplace_back(mask);
  }

  // Handmade case
  if(namecontains("hand00_task1")) {
    // 同じクエリが飛んでくるけど、オンラインクエリ故に答えが異なるケース
    n      = MaxN;
    q      = 3;
    println(n, q);
    println("2 1 1000000000");
    println("1 1 1000000000 100 1000");
    println("2 1 1000000000");
    return 0;
  } else if(namecontains("hand01_task1") || namecontains("hand03_all")) {
    // 最初に全連結な直線グラフを作成して、その後ランダムにクエリを生成
    n      = MaxN;
    q      = maxQ;
    lr_num = q / 2;
    println(n, q);
    for(int i = 0; i < lr_num - 1; i++) {
        int l = rnd.next(1, n);
        int r = rnd.next(l, n);
        println("1", lr[i], lr[i + 1], l, r);
        q--;
        if(q <= 0) return 0;
    }
    while(q--) {
        int L = rnd.next(1, lr_num - 2);
        int R = rnd.next(L + 1, lr_num - 1);
        println(2, lr[L], lr[R]);
    }
    return 0;
  } else if(namecontains("hand02_task1") || namecontains("hand04_all")) {
    // 最初に全連結な直線グラフを作成して、その後の残り全てのクエリを端から端までのクエリにする
    n      = MaxN;
    q      = maxQ;
    lr_num = q / 2;
    println(n, q);
    for(int i = 0; i < lr_num - 1; i++) {
        int l = rnd.next(1, n);
        int r = rnd.next(l, n);
        println("1", lr[i], lr[i + 1], l, r);
        q--;
        if(q <= 0) return 0;
    }
    while(q--) println(2, lr[0], lr[lr_num - 1]);
    return 0;
  } else if(namecontains("hand05_all")) {
    // 最初の一つ以外全てクエリ 2
    n      = MaxN;
    q      = maxQ;
    lr_num = q / 2;
    println(n, q);
    println(1, 1, 1000000000, 1, 1000);
    q--;
    while(q--) println(2, 1, 1000000000);
    return 0;
  } 

  println(n, q);

  // クエリ生成
  weighted_dsu uf(lr_num);
  for(int i = 0; i < q; i++) {
    // 原則クエリ 1 で LR が連結 && diff が 000...111...000 の形でないならクエリ 2 にする
    int t       = rnd.next(1, 2);
    int L = rnd.next(0, lr_num - 2);
    int R = rnd.next(L + 1, lr_num - 1);
    if(t == 1 && uf.same(L, R)) {
      bitset<bit_size> diff = uf.diff(L, R);
      bool flag_01          = (diff[0] == 1);
      bool flag_10          = false;
      bool ng               = false;

      for(int j = 1; j < bit_size; j++) {
        if(flag_10 && diff[j] == 1) {
          ng = true;
          break;
        } else if(flag_01 && diff[j] == 0) flag_10 = true;
        else if(diff[j] == 1) flag_01 = true;
      }
      if(ng || !flag_01) t = 2;
    }

    if(t == 1) {
      int l = rnd.next(1, n);
      int r = rnd.next(l, n);
      if(uf.same(L, R)) {
        bitset<bit_size> diff = uf.diff(L, R);
        for(int j = 0; j < bit_size; j++) {
          if(diff[j] == 0) continue;
          l = j + 1;
          break;
        }
        for(int j = bit_size - 1; j >= 0; j--) {
          if(diff[j] == 0) continue;
          r = j + 1;
          break;
        }
      } else uf.merge(L, R, masks[(r - 1) - (l - 1)] << (l - 1));
      L = lr[L];
      R = lr[R];
      println(t, L, R, l, r);
    } else {
      L = lr[L];
      R = lr[R];
      println(t, L, R);
    }
  }

  return 0;
}
