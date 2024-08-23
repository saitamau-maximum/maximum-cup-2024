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
    // c00 = 0, c01 = 1
    // c10 = 1, c11 = 0
    println(2, 0);
    println(0, 1);
    println(1, 0);
    return 0;
  }
  if (namecontains("hand01")) {
    // c00 = 0, c01 = 1
    // c10 = 2, c11 = 0
    println(3, 0);
    println(0, 1, 1);
    println(1, 0, 0);
    return 0;
  }
  if (namecontains("hand02")) {
    // c00 = 0, c01 = 2
    // c10 = 1, c11 = 0
    println(3, 0);
    println(0, 0, 1);
    println(1, 1, 0);
    return 0;
  }
  if (namecontains("hand03")) {
    // c00 = 1, c01 = 1
    // c10 = 1, c11 = 0
    println(3, 0);
    println(0, 0, 1);
    println(0, 1, 0);
    return 0;
  }
  if (namecontains("hand04")) {
    // c00 = 1, c01 = 1
    // c10 = 1, c11 = 1
    println(4, 0);
    println(0, 0, 1, 1);
    println(0, 1, 0, 1);
    return 0;
  }
  constexpr int MaxN = 200'000;
  if (namecontains("hand05")) {
    println(MaxN, 0);
    vector<int> alpha(MaxN, 0), beta(MaxN, 0);
    for (int i = 0; i < MaxN / 2; ++i) alpha[i] = beta[MaxN - i - 1] = 1;
    println(alpha);
    println(beta);
    return 0;
  }
  if (namecontains("hand06")) {
    println(MaxN, 0);
    vector<int> alpha(MaxN, 1), beta(MaxN, 1);
    for (int i = 0; i < MaxN / 2; ++i) alpha[i] = beta[MaxN - i - 1] = 0;
    println(alpha);
    println(beta);
    return 0;
  }
  if (namecontains("hand07")) {
    println(MaxN, 0);
    vector<int> alpha(MaxN, 0), beta(MaxN, 0);
    alpha[0] = beta[1] = 1;
    println(alpha);
    println(beta);
    return 0;
  }
  if (namecontains("hand08")) {
    println(MaxN, 0);
    vector<int> alpha(MaxN, 0), beta(MaxN, 0);
    alpha[1] = beta[0] = 1;
    println(alpha);
    println(beta);
    return 0;
  }
  if (namecontains("hand09")) {
    println(MaxN, 0);
    vector<int> alpha(MaxN, 1), beta(MaxN, 1);
    alpha[0] = beta[1] = 0;
    println(alpha);
    println(beta);
    return 0;
  }
  if (namecontains("hand10")) {
    println(MaxN, 0);
    vector<int> alpha(MaxN, 1), beta(MaxN, 1);
    alpha[1] = beta[0] = 0;
    println(alpha);
    println(beta);
    return 0;
  }

  // ---------- others ---------- //
  int n = -1, m = -1;
  int param_free = -1, param_left = -1, param_right = -1;

  // task1
  if (namecontains("task1")) {
    if (namecontains("max")) {
      n = 8;
    }
    else if (namecontains("min")) {
      // m = 0 は hand00 でカバー
      n = 2;
    }
    else {
      n = rnd.next(3, 7);  // 3 <= n <= 7 (2, 8 は上でカバー)
    }
  }
  else if (namecontains("all")) {
    if (namecontains("max")) {
      n = 200'000;
    }
    else if (namecontains("random01")) {
      n = 25;
    }
    else {
      n = rnd.next(3, 200'000);
    }
  }
  else {
    cerr << "Invalid filename: " << filename << endl;
    return 1;
  }

  param_free = rnd.next(0, n);
  param_left = rnd.next(0, n - param_free);
  param_right = n - param_free - param_left;
  m = rnd.next(0, (int) min((long long) param_left * param_right, 200'000LL));

  if (namecontains("min00") || namecontains("min01")) m = 1;
  if (namecontains("max00") || namecontains("max01")) m = 0;                      // 無辺
  if (namecontains("max02") || namecontains("max03")) m = n - 1;                  // スターグラフ
  if (namecontains("max04_task1") || namecontains("max05_task1")) m = n * n / 4;  // n/2, n/2 の完全グラフ
  if (namecontains("random05") || namecontains("random06") || namecontains("random07") || namecontains("random08") || namecontains("random09") || namecontains("max04_all") || namecontains("max05_all")) {
    m = 1;
    param_free = n - 2, param_left = 1, param_right = 1;
  }

  println(n, m);

  // ---------- 辺の生成 ---------- //
  if (namecontains("min00") || namecontains("min01")) {
    println(1, 2);
  }
  else if (namecontains("max02") || namecontains("max03")) {
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
    // [1, param_free]: 孤立点
    // [param_free+1, param_free+param_left]: 左側の完全グラフ
    // [param_free+param_left+1, n]: 右側の完全グラフ
    set<pair<int, int>> edges;
    while (edges.size() < m) {
      int u = rnd.next(1, param_left) + param_free;
      int v = rnd.next(1, param_right) + param_free + param_left;
      edges.insert({ u, v });
    }
    vector<pair<int, int>> edges_vec(edges.begin(), edges.end());
    shuffle(edges_vec.begin(), edges_vec.end());
    for (auto [u, v] : edges_vec) println(u, v);
  }

  // ---------- alpha, beta の生成 ---------- //
  vector<int> alpha(n), beta(n);
  if (namecontains("min00")) {
    // 2 頂点 1 辺の alpha = beta
    alpha = beta = { 0, 1 };
  }
  else if (namecontains("min01")) {
    // 2 頂点 1 辺の alpha != beta
    alpha = { 0, 1 }, beta = { 1, 0 };
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
    if (namecontains("random00")) {
      // 二部グラフ内で異なるものを入れる
      for (int i = 0; i < param_free; ++i) alpha[i] = rnd.next(0, 1);
      for (int i = 0; i < param_left; ++i) alpha[i + param_free] = 0;
      for (int i = 0; i < param_right; ++i) alpha[i + param_free + param_left] = 1;
      for (int i = 0; i < param_free; ++i) beta[i] = rnd.next(0, 1);
      for (int i = 0; i < param_left; ++i) beta[i + param_free] = 1;
      for (int i = 0; i < param_right; ++i) beta[i + param_free + param_left] = 0;
    }
    else {
      // ランダムに
      for (int i = 0; i < param_free; ++i) alpha[i] = rnd.next(0, 1);
      for (int i = 0; i < param_left; ++i) alpha[i + param_free] = 0;
      for (int i = 0; i < param_right; ++i) alpha[i + param_free + param_left] = 1;
      for (int i = 0; i < param_free; ++i) beta[i] = rnd.next(0, 1);
      for (int i = 0; i < param_left; ++i) beta[i + param_free] = 0;
      for (int i = 0; i < param_right; ++i) beta[i + param_free + param_left] = 1;
    }

    // 個数を数えて良い彩色でなければ適当に変える
    int cnt_alpha_0 = 0, cnt_alpha_1 = 0;
    int cnt_beta_0 = 0, cnt_beta_1 = 0;
    for (int i = 0; i < n; ++i) {
      (alpha[i] == 0 ? cnt_alpha_0 : cnt_alpha_1)++;
      (beta[i] == 0 ? cnt_beta_0 : cnt_beta_1)++;
    }
    // 0 or 1 どちらか一方のみ実行されるはず
    ensure(cnt_alpha_0 + cnt_alpha_1 >= 2);
    if (cnt_alpha_0 == 0) alpha[rnd.next(0, param_free - 1)] = 0;
    if (cnt_alpha_1 == 0) alpha[rnd.next(param_free, param_free + param_left - 1)] = 1;

    ensure(cnt_beta_0 + cnt_beta_1 >= 2);
    if (cnt_beta_0 == 0) beta[rnd.next(0, param_free - 1)] = 0;
    if (cnt_beta_1 == 0) beta[rnd.next(param_free, param_free + param_left - 1)] = 1;
  }

  println(alpha);
  println(beta);

  return 0;
}
