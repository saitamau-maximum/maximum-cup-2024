#include "testlib.h"

#include <vector>
using namespace std;

// ファイル名に含まれるかどうか
#define namecontains(t) (filename.find(t) != string::npos)

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  constexpr long long MaxA = 10'000'000'000'000'000;  // 1e16
  const string filename = argv[1];

  int n = -1;
  vector<long long> a;

  // task1
  if (namecontains("task1")) {
    if (namecontains("max")) {
      n = 200;
      a.assign(n, 1);
    }
    else if (namecontains("min")) {
      n = 1;
      a.assign(n, rnd.next(1LL, MaxA));
    }
    else {
      n = rnd.next(1, 200);  // 1 <= n <= 200
      a.assign(n, 1);
    }
  }
  else if (namecontains("all")) {
    if (namecontains("max")) {
      n = 200'000;
    }
    // min は task1 にあるのでなし
    else {
      n = rnd.next(1, 200'000);  // 1 <= n <= 200'000
    }
    a.assign(n, 1);
  }
  else {
    cerr << "Invalid filename: " << filename << endl;
    return 1;
  }

  println(n);

  int continue_count = 0;

  for (int i = 1; i < n; i++) {
    // random00-04, max00-03, hand00

    if (namecontains("random04") || namecontains("max03")) {
      // 全部同じ値
      if (i == 1) {
        a.assign(n, rnd.next(1LL, MaxA));
        break;
      }
    }
    else if (namecontains("hand00")) {
      // 全部 0
      break;
    }
    else if (continue_count == 0) {
      if (namecontains("random00")) {
        // 適当に
        long long t = rnd.next(2, 50);
        if (t * a[i - 1] > MaxA) break;
        a[i] = t * a[i - 1];
      }
      else if (namecontains("random01") || namecontains("max00")) {
        // 適当に、ただし 3 倍まで
        long long t = rnd.next(2, 3);
        if (t * a[i - 1] > MaxA) break;
        a[i] = t * a[i - 1];
      }
      else if (namecontains("random02") || namecontains("max01")) {
        // 適当な値からスタートさせる
        if (i == 1) a.assign(n, rnd.next(1LL, 100'000LL));
        long long t = rnd.next(2, 3);
        if (t * a[i - 1] > MaxA) break;
        a[i] = t * a[i - 1];
      }
      else if (namecontains("random03") || namecontains("max02")) {
        // 2 冪
        long long t = 2;
        if (t * a[i - 1] > MaxA) break;
        a[i] = t * a[i - 1];
      }

      continue_count = rnd.next(0, n / 50);
    }
    else {
      a[i] = a[i - 1];
      continue_count--;
    }
  }
  sort(a.begin(), a.end());
  println(a);
  return 0;
}
