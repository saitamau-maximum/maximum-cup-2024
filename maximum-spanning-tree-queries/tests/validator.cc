#include "dsu.hpp"
#include "testlib.h"

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  int n = inf.readInt(1, 200'000, "n");
  inf.readSpace();
  int m = inf.readInt(n - 1, 200'000, "m");
  inf.readEoln();
  atcoder::dsu d(n);
  for (int i = 0; i < m; ++i) {
    int a = inf.readInt(1, n, "u");
    inf.readSpace();
    int b = inf.readInt(1, n, "v");
    inf.readSpace();
    int c = inf.readInt(1, 1'000'000'000, "c");
    inf.readEoln();
    ensuref(a != b, "u and v must be different");
    d.merge(a - 1, b - 1);
  }
  ensuref(d.groups().size() == 1, "graph must be connected");
  int q = inf.readInt(1, 200'000, "q");
  inf.readEoln();
  for (int i = 0; i < q; ++i) {
    int a = inf.readInt(1, n, "x");
    inf.readSpace();
    int b = inf.readInt(1, n, "y");
    inf.readSpace();
    int c = inf.readInt(1, 1'000'000'000, "w");
    inf.readEoln();
    ensuref(a != b, "x and y must be different");
  }
  inf.readEof();
}
