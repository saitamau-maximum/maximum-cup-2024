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

  // 全列挙して求めておく
  vector<array<ll, 3>> ans(n, { 0, 0, 0 });
  const int pow3n = modpow(3, n);  // partial1 は n <= 12 なので 3^n = 531441 は 998244353 を超えない
  for (int state = 0; state < pow3n; ++state) {
    // 0: left, 1: mid, 2: right
    vector<int> stateVec(n);
    int tmp = state;
    for (int i = 0; i < n; ++i) {
      stateVec[i] = tmp % 3;
      tmp /= 3;
    }

    // L 伝播
    for (int i = n - 2; i >= 0; --i) {
      if (stateVec[i] == 1 && stateVec[i + 1] == 0) stateVec[i] = 0;
    }
    // R 伝播
    for (int i = 1; i < n; ++i) {
      if (stateVec[i] == 1 && stateVec[i - 1] == 2) stateVec[i] = 2;
    }

    for (int i = 0; i < n; ++i) ans[i][stateVec[i]]++;
  }
  const ll pow3ninv = modinv(pow3n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) ans[i][j] = ans[i][j] * pow3ninv % MOD;
  }

  // クエリ処理
  while (q--) {
    ll i;
    cin >> i;
    --i;
    cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << endl;
  }
  return 0;
}
