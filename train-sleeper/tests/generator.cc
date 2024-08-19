#include "testlib.h"

#include <vector>
using namespace std;

// ファイル名に含まれるかどうか
#define namecontains(t) (filename.find(t) != string::npos)

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  constexpr long long MaxN = 1'000'000'000'000'000'000;
  constexpr int MaxQ = 100'000;
  const string filename = argv[1];

  long long n = -1;
  int q = -1;

  if (namecontains("task1")) {
    if (namecontains("max")) {
      n = 12;
      q = MaxQ;
    }
    else if (namecontains("min")) {
      n = 1;
      q = 1;
    }
    else {
      n = rnd.next(1, 12);
      q = rnd.next(1, MaxQ);
    }
  }
  else if (namecontains("task2")) {
    if (namecontains("max")) {
      n = 100'000;
      q = MaxQ;
    }
    else {
      n = rnd.next(1, 100'000);
      q = rnd.next(1, MaxQ);
    }
  }
  else if (namecontains("all")) {
    if (namecontains("max")) {
      n = MaxN;
      q = MaxQ;
    }
    else {
      n = rnd.next(1LL, MaxN);
      q = rnd.next(1, MaxQ);
    }
  }
  else {
    cerr << "Invalid filename: " << filename << endl;
    return 1;
  }

  println(n, q);

  vector<long long> Query(q);
  set<long long> used;
  if (n <= q) {
    // いったんすべて詰め込んでランダムにとる
    for (int i = 0; i < n; ++i) Query[i] = i + 1;
    for (int i = n; i < q; ++i) Query[i] = rnd.next(1LL, n);
  }
  else {
    // 使ってないものからランダムに
    for (int i = 0; i < q; ++i) {
      long long x;
      do { x = rnd.next(1LL, n); } while (used.contains(x));
      Query[i] = x;
      used.insert(x);
    }
  }

  shuffle(Query.begin(), Query.end());

  for (int i = 0; i < q; ++i) println(Query[i]);

  return 0;
}
