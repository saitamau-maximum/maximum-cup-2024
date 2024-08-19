#include "testlib.h"

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  int h = inf.readInt(1, 1'000, "h");  // 1 <= h <= 1000
  inf.readSpace();                     // 空白
  int w = inf.readInt(1, 1'000, "w");  // 1 <= w <= 1000
  inf.readEoln();                      // 改行
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      inf.readInt(0, 1'000'000'000, "a[i][j]");  // 0 <= a[i][j] <= 1e9
      if (j < w - 1) inf.readSpace();            // 空白
    }
    inf.readEoln();  // 改行
  }
  inf.readEof();  // EOF
}
