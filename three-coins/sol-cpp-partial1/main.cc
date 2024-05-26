#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  set<ll> s;
  rep(i, n) rep(j, n) rep(k, n) {
    s.insert(a[i] + a[j] + a[k]);
  }
  ll ans = 0;
  for (ll x : s) ans ^= x;
  cout << ans << endl;
}
