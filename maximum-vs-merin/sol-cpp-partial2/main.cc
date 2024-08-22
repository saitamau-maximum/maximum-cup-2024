#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MAX_H = 1000;
vector<ll> grundy(MAX_H + 1, 0);

string solve_grundy(vector<pair<ll, ll>> slimes) {
  ll ans = 0;
  for(auto &&[h, c]: slimes) {
    if(c % 2 == 0) continue;
    ans ^= grundy[h];
  }
  return (ans != 0 ? "Maximum" : "Merin");
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll q, damage;
  cin >> q >> damage;

  // Grundy 数を前計算
  grundy.assign(MAX_H + 1, 0);
  vector<ll> tmp_mex(2 * MAX_H, 0);
  for(int i = 1; i <= MAX_H; i++) {
    for(int j = 1; j <= min((int) damage, i); j++) {
      ll ele = grundy[i - j];
      if(ele < 2 * MAX_H) tmp_mex[ele] = i;
    }
    for(int j = 1; j <= i / 2; j++) {
      ll ele = grundy[j] ^ grundy[i - j];
      if(ele < 2 * MAX_H) tmp_mex[ele] = i;
    }
    while(tmp_mex[grundy[i]] == i) grundy[i]++;
  }

  while(q--) {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> slimes;
    for(int i = 0; i < n; i++) {
      ll h, c;
      cin >> h >> c;
      slimes.emplace_back(h, c);
    }
    cout << solve_grundy(slimes) << '\n';
  }

  return 0;
}
