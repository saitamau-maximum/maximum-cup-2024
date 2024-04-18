#include "testlib.h"

#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  constexpr long long MaxA = 1'000'000'000'000;  // 1e12

  // task1
  // int n = rnd.next(1, 200);  // 1 <= n <= 100

  // task1 hand (max)
  // int n = 200;

  // task1 hand3
  // int n = 1;

  // all
  int n = rnd.next(1, 200'000);  // 2e5

  // all hand (max)

  println(n);
  vector<long long> a(n, 0);

  // task1 hand3
  // a[0] = rnd.next(0LL, MaxA);

  for (int i = 1; i < n; i++) {
    // random0-2
    // if (2LL * a[i - 1] > MaxA) break;
    // a[i] = rnd.next(2LL * a[i - 1], MaxA);

    // random3-5
    // if (2LL * a[i - 1] + 10 > MaxA) break;
    // a[i] = rnd.next(2LL * a[i - 1], 2LL * a[i - 1] + 10);

    // 2 倍ずつ (random 6-8)
    // if (2LL * a[i - 1] > MaxA) break;
    // if (i == 1) a[0] = rnd.next(1, 50);
    // a[i] = 2LL * a[i - 1];

    // 1 から 2 倍ずつ (hand 0)
    // if (2LL * a[i - 1] > MaxA) break;
    // if (i == 1) a[0] = 1;
    // a[i] = 2LL * a[i - 1];

    // Max から半分ずつ (hand 1)
    // if (i == 1) a[0] = MaxA;
    // a[i] = a[i - 1] / 2;

    // all 0 (hand 2)
    a[i] = 0;
  }
  sort(a.begin(), a.end());
  println(a);
  return 0;
}
