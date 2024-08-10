#include "testlib.h"

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  
  // 1 <= n <= 2e5
  int n = inf.readInt(1, 200'000, "n");
  inf.readSpace();                             
  // 1 <= d <= 1e9
  int d = inf.readInt(1, 1'000'000'000, "d");  
  inf.readEoln();                             
  
  for (int i = 0; i < n; ++i) {
    // 0 <= h[i] <= 1e9
    long long h = inf.readLong(1LL, 1'000'000'000, format("h[%d]", i));  
    inf.readSpace();                                                     
    // 0 <= c[i] <= 1e9
    long long c = inf.readLong(1LL, 1'000'000'000, format("c[%d]", i));  
    inf.readEoln();  // 各行の終わりに改行
  }
  
  inf.readEof();  // EOF
}
