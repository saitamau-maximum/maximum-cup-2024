#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

constexpr int MOD = 998244353;

inline ll modpow(ll a, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return res;
}

inline ll modinv(ll a) { return modpow(a % MOD, MOD - 2); }

int main() {
  ll n;
  int q;
  cin >> n >> q;

  // 前計算して求めておく
  const ll onethird = modinv(3);
  // 0: left, 1: mid, 2: right
  vector<array<ll, 3>> dp(n, { onethird, onethird, onethird });
  // L 伝播
  for (int i = n - 2; i >= 0; --i) {
    ll x = dp[i][1] * dp[i + 1][0] % MOD;
    dp[i][0] = (dp[i][0] + x) % MOD;
    dp[i][1] = (dp[i][1] - x + MOD) % MOD;
  }
  // R 伝播
  for (int i = 1; i < n; ++i) {
    ll y = dp[i][1] * dp[i - 1][2] % MOD;
    dp[i][2] = (dp[i][2] + y) % MOD;
    dp[i][1] = (dp[i][1] - y + MOD) % MOD;
  }

  // クエリ処理
  while (q--) {
    ll i;
    cin >> i;
    --i;
    cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << endl;
  }
  return 0;
}
