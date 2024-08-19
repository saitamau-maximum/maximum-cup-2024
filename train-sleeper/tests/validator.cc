#include "testlib.h"

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  long long n = inf.readLong(1LL, 1'000'000'000'000'000'000, "n");
  inf.readSpace();
  int q = inf.readInt(1, 100'000, "q");
  inf.readEoln();
  for (int _ = 0; _ < q; ++_) {
    long long i = inf.readLong(1LL, n, "i");
    inf.readEoln();
  }
  inf.readEof();
}
