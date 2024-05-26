#include "testlib.h"

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  int n = inf.readInt(1, 200'000, "n");  // 1 <= n <= 2e5
  inf.readEoln();                        // 改行
  long long prev = 1;
  for (int i = 0; i < n; ++i) {
    if (i > 0) inf.readSpace();                                                     // 空白
    long long now = inf.readLong(0LL, 10'000'000'000'000'000, format("a[%d]", i));  // 0 <= a[i] <= 1e16
    ensuref(now % prev == 0, "a[%d] = %lld, a[%d] = %lld", i - 1, prev, i, now);
    prev = now;
  }
  inf.readEoln();  // 改行
  inf.readEof();   // EOF
}
