#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);

  int n = inf.readInt(2, 200'000, "n");
  inf.readSpace();
  int m = inf.readInt(1, (int) min(200'000LL, (long long) n * (n - 1)), "m");
  inf.readEoln();

  vector<int> c = inf.readInts(n, 0, 100'000, "c");
  inf.readEoln();
  for (int i = 0; i < m; ++i) {
    int u = inf.readInt(1, n, "u");
    inf.readSpace();
    int v = inf.readInt(1, n, "v");
    inf.readSpace();
    int h = inf.readInt(1, 100'000, "h");
    inf.readEoln();
    ensuref(u != v, "u and v must be different");
  }
  inf.readEof();
}
