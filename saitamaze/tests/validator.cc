#include "testlib.h"
#include <map>
using namespace std;

int main(int argc, char* argv[]) {
  registerValidation(argc, argv);
  int h = inf.readInt(1, 100, "n");  // 1 <= h <= 100
  inf.readSpace();                     // 空白
  int w = inf.readInt(1, 100, "n");  // 1 <= w <= 100
  inf.readEoln();                      // 改行
  
  map<int, int> cnt;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      int h = inf.readInt(0, 1'000'000'000, format("h[%d][%d]", i, j));  // 0 <= x[i][j] <= 1e9
      cnt[h]++;
      if(j != w - 1) inf.readSpace();  // 空白
      else inf.readEoln();             // 改行
      ensuref(cnt[h] <= 100, "h[%d][%d] = %d, cnt[%d] = %d", i, j, h, h, cnt[h]);
    }
  }
  inf.readEof();   // EOF
}
