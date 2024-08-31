#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string solve_dp(ll n, ll damage, vector<pair<ll, ll>> slimes) {
  ll h_max = 0;
  for(auto &[h, c]: slimes) h_max = max(h_max, h);

  vector<ll> h_cnt(h_max + 1, 0);
  for(auto &[h, c]: slimes) h_cnt[h] = c;

  map<vector<ll>, bool> memo;

  function<bool()> dfs = [&]() -> bool {
    if(memo.count(h_cnt)) return memo[h_cnt];
    bool res = false;

    // 分割遷移
    for(int i = 2; i <= h_max; ++i) {
      if(h_cnt[i] == 0) continue;
      h_cnt[i]--;
      for(int j = 1; j <= i / 2; ++j) {
        h_cnt[j]++;
        h_cnt[i - j]++;
        res |= !dfs();
        h_cnt[j]--;
        h_cnt[i - j]--;
        if(res) break;
      }
      h_cnt[i]++;
      if(res) break;
    }

    // 消費遷移
    if(!res) {
      for(int i = 1; i <= h_max; ++i) {
        if(h_cnt[i] == 0) continue;
        h_cnt[i]--;
        for(int j = 1; j <= min((int) damage, i); ++j) {
          if(i - j != 0) h_cnt[i - j]++;
          res |= !dfs();
          if(i - j != 0) h_cnt[i - j]--;
          if(res) break;
        }
        h_cnt[i]++;
        if(res) break;
      }
    }

    memo[h_cnt] = res;
    return res;
  };

  return dfs() ? "Maximum" : "Merin";
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
      ll h, c;
      cin >> h >> c;
      slimes.emplace_back(h, c);
    }
    cout << solve_dp(n, damage, slimes) << '\n';
  }

  return 0;
}
