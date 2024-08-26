#include "testlib.h"

using namespace std;

inline void quitWithPoint(int point, TResult result, string message) {
  bool is_mofe = true;  // TODO: change here
  if (is_mofe) {
    cout << "MofeJudge::Score(" << point << ")" << endl;
    quit(result, message);
  }
  else {
    quit(result, message);
  }
}

int main(int argc, char *argv[]) {
  setName("minimum-changes-on-bipartite-coloring custom judge");
  registerTestlibCmd(argc, argv);

  // まず入力を読む
  int n = inf.readInt();
  int m = inf.readInt();
  vector<int> deg(n, 0);
  for (int i = 0; i < m; i++) {
    int u = inf.readInt() - 1;
    int v = inf.readInt() - 1;
    ++deg[u], ++deg[v];
  }
  vector<int> alpha = inf.readInts(n);
  vector<int> beta = inf.readInts(n);

  // 最小操作回数が答えと一致しているかチェック
  int ans_op = ans.readInt();
  int out_op = ouf.readInt();
  if (ans_op != out_op) {
    // 異なっていれば WA
    quitWithPoint(0, _wa, "wrong operation count");
  }

  // コーナーケースを all に含めたいので
  // token 2 が 0 の場合は all とみなす
  bool isTask1 = n <= 8 && (ans.seekEof() || ans.readInt() != 0);

  if (ans_op == -1) {
    if (ouf.seekEof())
      quitWithPoint(isTask1 ? 30 : 70, _ok, "operation count is -1");
    else
      quitWithPoint(0, _wa, "expected operation count is -1, but found some operations");
  }

  // 正しい操作列かチェック
  const int point = (isTask1 ? 10 : 25);
  int op_cnt = 0;
  int cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < n; ++i) (alpha[i] == 0 ? cnt0 : cnt1)++;
  while (!ouf.seekEof()) {
    ++op_cnt;
    int v = ouf.readInt();
    int c = ouf.readInt();
    if (!(1 <= v && v <= n)) quitWithPoint(point, _partially, "invalid vertex number");
    if (c != 0 && c != 1) quitWithPoint(point, _partially, "invalid color");

    --v;
    if (alpha[v] == c) quitWithPoint(point, _partially, "changing to the same color");
    if (deg[v] != 0) quitWithPoint(point, _partially, "changing color of a vertex with neighbors");
    if (c == 0 && cnt1 == 1) quitWithPoint(point, _partially, "color 1 will be empty");
    if (c == 1 && cnt0 == 1) quitWithPoint(point, _partially, "color 0 will be empty");

    alpha[v] = c;
    if (c == 0)
      cnt0++, cnt1--;
    else
      cnt0--, cnt1++;
  }

  if (op_cnt > ans_op) quitWithPoint(point, _partially, "operation count is greater than expected");
  if (op_cnt < ans_op) quitWithPoint(point, _partially, "operation count is less than expected");

  quitWithPoint(isTask1 ? 30 : 70, _ok, "correct operation count");
}
