#include "testlib.h"

#include <vector>
using namespace std;

// ファイル名に含まれるかどうか
#define namecontains(t) (filename.find(t) != string::npos)

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  constexpr int MaxN = 200'000;
  constexpr int MaxT = 10000;
  constexpr int MaxC = 10000;
  const string filename = argv[1];

  const auto MaxM = [&](int n) {
    return (int) min(200'000LL, (long long) n * (n - 1));
  };

  // ---------- hand ---------- //
  if (namecontains("hand00")) {
    // 完全二分木 (2^17 - 1)
    int n = 131072 - 1;
    int m = n - 1;
    println(n, m);
    vector<int> c(n, MaxC);
    if (namecontains("task1")) c.assign(n, 0);
    println(c);
    vector<int> perm = rnd.perm(n);
    for (int v = 2; v <= n; ++v) {
      println(perm[(v / 2) - 1] + 1, perm[v - 1] + 1, MaxT);
    }
    return 0;
  }
  if (namecontains("hand01")) {
    // 直鎖状
    int n = MaxN;
    int m = n - 1;
    println(n, m);
    vector<int> c(n, MaxC);
    if (namecontains("task1")) c.assign(n, 0);
    println(c);
    vector<int> perm = rnd.perm(n);
    for (int i = 0; i < n - 1; ++i) {
      println(perm[i] + 1, perm[i + 1] + 1, MaxT);
    }
    return 0;
  }

  // ---------- other ---------- //
  int n = -1, m = -1;

  if (namecontains("task1")) {
    if (namecontains("max")) {
      n = MaxN;
      m = MaxM(n);
    }
    else if (namecontains("min")) {
      n = 2;
      if (namecontains("min00")) m = 2;
      if (namecontains("min01")) m = 1;
    }
    else {
      n = rnd.next(2, MaxN);
      m = rnd.next(1, MaxM(n));
    }
  }
  else if (namecontains("task2")) {
    if (namecontains("max")) {
      n = MaxN;
    }
    else if (namecontains("min")) {
      n = 2;
    }
    else {
      n = rnd.next(2, MaxN);
    }
    m = n - 1;
  }
  else if (namecontains("all")) {
    if (namecontains("max")) {
      n = MaxN;
      m = MaxM(n);
    }
    else if (namecontains("min")) {
      n = 2;
      if (namecontains("min00")) m = 2;
      if (namecontains("min01")) m = 1;
    }
    else {
      n = rnd.next(2, MaxN);
      m = MaxM(n);
    }
  }
  else {
    cerr << "Invalid filename: " << filename << endl;
    return 1;
  }

  println(n, m);

  vector<int> c(n, 0);
  if (!namecontains("task1")) {
    for (int i = 0; i < n; ++i) c[i] = rnd.next(0, MaxC);
    if (namecontains("max")) c.assign(n, MaxC);
  }
  println(c);

  if (namecontains("task2")) {
    // connected DAG
    vector<int> par(n, -1);
    for (int i = 1; i < n; ++i) par[i] = rnd.next(0, i - 1);
    vector<int> perm = rnd.perm(n);
    for (int i = 1; i < n; ++i) {
      println(perm[par[i]] + 1, perm[i] + 1, rnd.next(1, MaxT));
    }
  }
  else {
    // 時間かかりそうなのでかなり衝突しそうなやつは先にあげておく
    bool notusedListAvailable = m * 10 >= (long long) n * (n - 1);
    vector<pair<int, int>> notusedEdges;
    if (notusedListAvailable) {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          if (i != j) notusedEdges.push_back({ i, j });
        }
      }
    }
    shuffle(notusedEdges.begin(), notusedEdges.end());

    set<pair<int, int>> edges;
    // rand00, min00, max00: 閉路を含む
    if (namecontains("random00") || namecontains("min00") || namecontains("max00")) {
      // 閉路
      int siz = rnd.next(2, n);
      vector<int> cycle = rnd.perm(n);
      while (cycle.size() > siz) cycle.pop_back();
      for (int i = 0; i < siz; ++i) edges.insert({ cycle[i] + 1, cycle[(i + 1) % siz] + 1 });
      // その他は適当に
      while (edges.size() < m) {
        if (notusedListAvailable) {
          edges.insert(notusedEdges.back());
          notusedEdges.pop_back();
        }
        else {
          int u = rnd.next(1, n);
          int v = rnd.next(1, n);
          while (u == v) v = rnd.next(1, n);
          if (!edges.contains({ u, v })) edges.insert({ u, v });
        }
      }
    }
    else {
      vector<int> perm = rnd.perm(n);
      while (edges.size() < m) {
        if (notusedListAvailable) {
          if (notusedEdges.empty()) {
            cerr << "too large m" << endl;
            return 1;
          }
          auto [u, v] = notusedEdges.back();
          notusedEdges.pop_back();
          if (u > v) continue;
          edges.insert({ perm[u - 1] + 1, perm[v - 1] + 1 });
        }
        else {
          int u = rnd.next(0, n - 2);
          int v = rnd.next(u + 1, n - 1);
          edges.insert({ perm[u] + 1, perm[v] + 1 });
        }
      }
    }

    vector<pair<int, int>> edg(edges.begin(), edges.end());
    shuffle(edg.begin(), edg.end());
    for (int i = 0; i < edg.size(); ++i) {
      int t = rnd.next(1, MaxT);
      if (namecontains("max")) t = MaxT;
      println(edg[i].first, edg[i].second, t);
    }
  }

  return 0;
}
