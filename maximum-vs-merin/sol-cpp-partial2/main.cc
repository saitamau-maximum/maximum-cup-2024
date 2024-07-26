#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solve_grundy(ll n, ll damage, vector<pair<ll, ll>> slimes) {
  // ========== Grundy 数を O(max(H)^2) で求める解法 ========== //
  ll h_max = 0;
  for(int i = 0; i < n; i++) h_max = max(h_max, slimes[i].first);
  vector<ll> h_cnt(h_max + 1, 0);
  for(int i = 0; i < n; i++) h_cnt[slimes[i].first] += slimes[i].second;

  vector<ll> grundy(h_max + 1, 0);
  for(int i = 1; i <= h_max; i++) {
    set<ll> s;
    for(int j = 1; j <= min((int) damage, i); j++) s.insert(grundy[i - j]);
    for(int j = 1; j <= i / 2; j++) s.insert(grundy[j] ^ grundy[i - j]);
    while(s.count(grundy[i])) grundy[i]++;
  }

  ll ans = 0;
  for(int i = 0; i < h_max + 1; i++) {
    if(h_cnt[i] % 2 == 0) continue;
    ans ^= grundy[i];
  }
  return (ans != 0 ? "Maximum" : "Merin");
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll n, damage;
  vector<pair<ll, ll>> slimes;
  cin >> n >> damage;
  for(int i = 0; i < n; i++) {
    ll h, c;
    cin >> h >> c;
    slimes.emplace_back(pair(h, c));
  }
  cout << solve_grundy(n, damage, slimes) << '\n';

  return 0;
}
