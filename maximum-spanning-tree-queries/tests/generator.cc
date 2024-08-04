#include "testlib.h"

#include <vector>
using namespace std;

// ファイル名に含まれるかどうか
#define namecontains(t) (filename.find(t) != string::npos)

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  const string filename = argv[1];

  int n = -1, m = -1, q = -1;

  if (namecontains("task1")) {
    if (namecontains("max")) {
      n = 100, m = 100, q = 1000;
    }
    else if (namecontains("min")) {
      n = 2, m = 1, q = 1;
    }
    else {
      n = rnd.next(2, 100);
      m = rnd.next(n - 1, 100);
      q = rnd.next(1, 1000);
    }
  }
  else if (namecontains("task2")) {
    if (namecontains("max")) {
      n = 100, m = 200'000, q = 1000;
    }
    else {
      n = rnd.next(2, 100);
      m = rnd.next(n - 1, 200'000);
      q = rnd.next(1, 1000);
    }
  }
  else if (namecontains("all")) {
    if (namecontains("max")) {
      n = 200'000, m = 200'000, q = 200'000;
    }
    else {
      n = rnd.next(2, 200'000);
      m = rnd.next(n - 1, 200'000);
      q = rnd.next(1, 200'000);
    }
  }
  else {
    cerr << "Invalid filename: " << filename << endl;
    return 1;
  }

  vector<int> par(n);
  for (int i = 1; i < n; ++i) par[i] = rnd.next(0, i - 1);

  vector<tuple<int, int, int>> edges(m);
  int maximWeight = 0;
  for (int i = 1; i <= m; ++i) {
    if (i <= n - 1) {
      if (rnd.next(0, 1))
        edges[i - 1] = { i, par[i], rnd.next(1, 1'000'000'000) };
      else
        edges[i - 1] = { par[i], i, rnd.next(1, 1'000'000'000) };
    }
    else {
      int u = rnd.next(0, n - 1);
      int v = rnd.next(0, n - 1);
      while (u == v) v = rnd.next(0, n - 1);
      edges[i - 1] = { u, v, rnd.next(1, 1'000'000'000) };
    }
    maximWeight = max(maximWeight, get<2>(edges[i]));
  }
  shuffle(edges.begin(), edges.end());
  if (namecontains("hand00") || namecontains("max00")) get<2>(edges[0]) = 1'000'000'000 - q;
  vector<int> perm = rnd.perm(n);

  println(n, m);
  for (auto [u, v, c] : edges) println(perm[u] + 1, perm[v] + 1, c);

  println(q);
  for (int _ = 0; _ < q; ++_) {
    // random00, max00 は完全ランダム
    if (namecontains("random00") || namecontains("max00")) {
      int u = rnd.next(1, n);
      int v = rnd.next(1, n);
      while (u == v) v = rnd.next(1, n);
      println(u, v, rnd.next(1, 1'000'000'000));
    }
    // どんどん重みを増やしていく
    else if (namecontains("hand00") || namecontains("max01")) {
      auto [u, v, c] = edges[0];
      ensure(c + _ + 1 <= 1'000'000'000);
      println(u + 1, v + 1, c + _ + 1);
    }
    else {
      // 重めな辺を選ぶ
      int u = rnd.next(1, n);
      int v = rnd.next(1, n);
      while (u == v) v = rnd.next(1, n);
      println(u, v, rnd.next(maximWeight + 1, 1'000'000'000));
    }
  }

  return 0;
}
