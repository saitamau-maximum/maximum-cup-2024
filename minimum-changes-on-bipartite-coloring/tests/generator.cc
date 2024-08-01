#include "testlib.h"

#include <vector>
using namespace std;

// ファイル名に含まれるかどうか
#define namecontains(t) (filename.find(t) != string::npos)

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  const string filename = argv[1];

  // ---------- hand ---------- //
  if (namecontains("hand00")) {
    println(2, 0);
    println(0, 1);
    println(1, 0);
    return 0;
  }

  // ---------- others ---------- //
  int n = -1, m = -1;

  // task1
  if (namecontains("task1")) {
    if (namecontains("max")) {
      n = 8;
    }
    else if (namecontains("min")) {
      n = 1, m = 0;
    }
    else {
      n = rnd.next(2, 7);  // 2 <= n <= 7 (1, 8 は上でカバー)
    }
  }
  else if (namecontains("all")) {
    if (namecontains("max")) {
      n = 200'000;
    }
    else {
      // to be written
    }
  }
  else {
    cerr << "Invalid filename: " << filename << endl;
    return 1;
  }

  if (namecontains("max00") || namecontains("max01")) m = 0;                      // 無辺
  if (namecontains("max02") || namecontains("max03")) m = n - 1;                  // スターグラフ
  if (namecontains("max04_task1") || namecontains("max05_task1")) m = n * n / 4;  // n/2, n/2 の完全グラフ

  println(n, m);

  // ---------- 辺の生成 ---------- //
  if (namecontains("max02") || namecontains("max03")) {
    // スターグラフ
    for (int i = 2; i <= n; i++) println(1, i);
  }
  else if (namecontains("max04_task1") || namecontains("max05_task1")) {
    // n/2, n/2 の完全グラフ
    for (int i = 1; i <= n / 2; i++) {
      for (int j = n / 2 + 1; j <= n; j++) {
        println(i, j);
      }
    }
  }
  else {
    // その他のケース
    // to be written
  }

  // ---------- alpha, beta の生成 ---------- //
  vector<int> alpha(n), beta(n);
  if (namecontains("min00")) {
    // 1 頂点 0 辺の alpha = beta
    alpha = beta = { 0 };
  }
  else if (namecontains("min01")) {
    // 1 頂点 0 辺の alpha != beta
    alpha = { 0 }, beta = { 1 };
  }
  else if (namecontains("max00")) {
    // 無辺の alpha = beta
    for (int i = 0; i < n; ++i) alpha[i] = rnd.next(0, 1);
    beta = alpha;
  }
  else if (namecontains("max01")) {
    // 無辺の alpha != beta max
    for (int i = 0; i < n; ++i) alpha[i] = rnd.next(0, 1);
    for (int i = 0; i < n; ++i) beta[i] = alpha[i] ^ 1;
  }
  else if (namecontains("max02")) {
    // スターグラフ、 alpha = beta
    for (int i = 0; i < n; ++i) alpha[i] = (i == 0 ? 0 : 1);
    beta = alpha;
  }
  else if (namecontains("max03")) {
    // スターグラフ、 alpha != beta
    for (int i = 0; i < n; ++i) alpha[i] = (i == 0 ? 0 : 1);
    for (int i = 0; i < n; ++i) beta[i] = (i == 0 ? 1 : 0);
  }
  else if (namecontains("max04_task1")) {
    // 完全グラフ、 alpha = beta
    for (int i = 0; i < n; ++i) alpha[i] = (i < n / 2 ? 0 : 1);
    beta = alpha;
  }
  else if (namecontains("max05_task1")) {
    // 完全グラフ、 alpha != beta
    for (int i = 0; i < n; ++i) alpha[i] = (i < n / 2 ? 0 : 1);
    for (int i = 0; i < n; ++i) beta[i] = (i < n / 2 ? 1 : 0);
  }
  else {
    // その他のケース
    // to be written
  }

  println(alpha);
  println(beta);

  return 0;
}
