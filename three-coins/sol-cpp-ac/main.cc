#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  a.erase(unique(a.begin(), a.end()), a.end());
  set<ll> s;
  assert(a.size() <= 100);
  rep(i, a.size()) rep(j, a.size()) rep(k, a.size()) {
    s.insert(a[i] + a[j] + a[k]);
  }
  cout << s.size() << endl;
}
