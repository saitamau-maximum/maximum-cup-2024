#include "testlib.h"

#include <vector>
using namespace std;

// ファイル名に含まれるかどうか
#define namecontains(t) (filename.find(t) != string::npos)

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  constexpr int MaxA = 1'000'000'000;  // 1e9
  const string filename = argv[1];

  int h = -1, w = -1;
  vector<vector<int>> a;

  if (namecontains("all")) {
    if (namecontains("max")) {
      h = 1'000, w = 1'000;
    }
    else if (namecontains("min")) {
      h = 1, w = 1;
    }
    else {
      h = rnd.next(1, 1'000);
      w = rnd.next(1, 1'000);
    }
    a.assign(h, vector<int>(w));
  }
  else {
    cerr << "Invalid filename: " << filename << endl;
    return 1;
  }

  println(h, w);

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (namecontains("hand00") || namecontains("min00") || namecontains("max00")) {
        a[i][j] = 0;
      }
      else if (namecontains("hand01") || namecontains("min01") || namecontains("max01")) {
        a[i][j] = MaxA;
      }
      else {
        a[i][j] = rnd.next(0, MaxA);
      }
    }
  }

  for (int i = 0; i < h; ++i) println(a[i]);
  return 0;
}
