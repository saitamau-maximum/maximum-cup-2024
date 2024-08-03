#include "testlib.h"

#include <queue>
using namespace std;

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  int n = inf.readInt(2, 200'000, "n");  // 1 <= n <= 2e5

  inf.readSpace();

  long long m_max = (long long) n * n / 4;
  int m = inf.readInt(0, (int) (m_max, 200'000LL), "m");  // 0 <= m <= 2e5

  inf.readEoln();

  vector Graph(n, vector<int>(0));

  for (int i = 0; i < m; ++i) {
    int u = inf.readInt(1, n, "u");  // 1 <= u <= n
    inf.readSpace();
    int v = inf.readInt(u + 1, n, "v");  // u < v <= n
    inf.readEoln();
    --u, --v;
    Graph[u].push_back(v);
    Graph[v].push_back(u);
  }

  vector<int> alpha = inf.readInts(n, 0, 1, "alpha");  // 0 <= alpha[i] <= 1
  inf.readEoln();
  vector<int> beta = inf.readInts(n, 0, 1, "beta");  // 0 <= beta[i] <= 1
  inf.readEoln();
  inf.readEof();

  // 二部グラフ判定
  vector<int> color(n, -1);
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (color[i] != -1) continue;
    color[i] = 0;
    q.push(i);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int u : Graph[v]) {
        if (color[u] == -1) {
          color[u] = 1 - color[v];
          q.push(u);
        }
        else {
          ensure_ext(color[u] != color[v]);
        }
      }
    }
  }

  // alpha が適切な彩色か
  int cnt_alpha_0 = 0, cnt_alpha_1 = 0;
  for (int i = 0; i < n; ++i) {
    ensure(alpha[i] == 0 || alpha[i] == 1);
    if (alpha[i] == 0) ++cnt_alpha_0;
    if (alpha[i] == 1) ++cnt_alpha_1;
    for (int u : Graph[i]) ensure(alpha[i] != alpha[u]);
  }
  ensure(cnt_alpha_0 != 0);
  ensure(cnt_alpha_1 != 0);

  // beta が適切な彩色か
  int cnt_beta_0 = 0, cnt_beta_1 = 0;
  for (int i = 0; i < n; ++i) {
    ensure(beta[i] == 0 || beta[i] == 1);
    if (beta[i] == 0) ++cnt_beta_0;
    if (beta[i] == 1) ++cnt_beta_1;
    for (int u : Graph[i]) ensure(beta[i] != beta[u]);
  }
  ensure(cnt_beta_0 != 0);
  ensure(cnt_beta_1 != 0);

  return 0;
}
