#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solve_grundy_fast(ll n, ll damage, vector<pair<ll, ll>> slimes) {
  // grundy(x, d) : 二人の最大攻撃力が d で体力 x のスライムを倒す時の Grundy 数
  auto grundy = [&](ll x, ll d) -> ll {
    if(x == 0) return 0;
    x--;

    // d mod 4 で場合分け
    // 最初の周期で抜ける場合
    ll T1 = d + d % 2;
    if(x < T1) {
      ll res = x;
      if(x % 4 == 2) res++;
      else if(x % 4 == 3) res--;
      return res + 1;
    }

    // 2 周期目以降を考慮
    x -= T1;
    ll T2 = d + 2 - d % 2;
    if(d % 2 == 0) {
      if(x % T2 == 0) return 0;
      else if(x % T2 == 1) return d + 1;
      else {
        ll res = x % T2 - 2;
        if(res % 4 == 2) res++;
        else if(res % 4 == 3) res--;
        return res + 1;
      }
    } else {
      if(x % T2 == 0) return 0;
      else {
        ll res = x % T2 - 1;
        if(res % 4 == 0) res++;
        else if(res % 4 == 1) res--;
        return res + 1;
      }
    }
  };

  ll total_grundy = 0;
  for(int i = 0; i < n; i++) {
    auto &&[h, c] = slimes[i];
    if(c % 2 == 0) continue;
    total_grundy ^= grundy(h, damage);
  }
  return (total_grundy != 0 ? "Maximum" : "Merin");
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll q, damage;
  cin >> q >> damage;
  while(q--) {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> slimes;
    for(int i = 0; i < n; i++) {
      ll h, c; cin >> h >> c;
      slimes.emplace_back(h, c);
    }
    cout << solve_grundy_fast(n, damage, slimes) << '\n';
  }

  return 0;
}
