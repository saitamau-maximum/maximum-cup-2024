#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  ll n;
  cin >> n;
  // n H 3 = n+2 C 3 = (n+2)(n+1)n/6
  cout << (n + 2) * (n + 1) * n / 6 << endl;
}
