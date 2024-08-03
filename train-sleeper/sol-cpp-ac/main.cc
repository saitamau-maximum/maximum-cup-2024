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
  const ll onethird = modinv(3);
  while (q--) {
    ll i;
    cin >> i;
    ll l = onethird, m = onethird, r = onethird;
    // L 伝播
    ll p1 = modpow(3, n - i);
    ll x = m * (p1 - 1) % MOD * modinv(2 * p1) % MOD;
    l = (l + x) % MOD;
    m = (m - x + MOD) % MOD;
    // R 伝播
    ll p2 = modpow(3, i - 1);
    ll y = m * (p2 - 1) % MOD * modinv(2 * p2) % MOD;
    r = (r + y) % MOD;
    m = (m - y + MOD) % MOD;

    cout << l << ' ' << m << ' ' << r << endl;
  }
  return 0;
}
