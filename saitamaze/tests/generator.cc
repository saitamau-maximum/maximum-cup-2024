#include "testlib.h"
#include <vector>
using namespace std;

// ファイル名に含まれるかどうか
#define namecontains(t) (filename.find(t) != string::npos)

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
    
  // ファイル名の取得
  const string filename = argv[1];

  // 最大値の設定
  constexpr int MaxH = 200; // 200
  constexpr int MaxW = 200; // 200
  constexpr int MaxValue = 1000000000; // 1e9

  int h, w;
  if(namecontains("hand")) {
    if(namecontains("hand00")) {
      h = 7;
      w = 7;
      println(h, w);
      println("3 1 4 1 5 9 2");
      println("6 5 3 5 8 9 7");
      println("9 3 2 3 8 4 6");
      println("2 6 4 3 1 8 1");
      println("2 7 9 5 3 2 8");
      println("8 4 1 9 7 4 6");
      println("5 6 7 2 4 7 1");
    } else if(namecontains("hand01")) {
      h = 10;
      w = 10;
      println(h, w);
      println("87 10 23 52 38 51 36 79 31 95");
      println("19 44 75 76 55 99 32 33 16 21");
      println("92 97 87 82 11 41 54 19 55 96");
      println("98 33 72 62 95 15 38 69 20 70");
      println("74 37 56 48 23 63 64 77 93 29");
      println("85 43 78 10 68 96 67 21 88 20");
      println("42 82 34 99 16 83 35 26 87 78");
      println("14 93 49 59 69 94 12 71 83 84");
      println("99 12 66 24 64 11 88 44 57 22");
      println("93 15 21 55 59 14 66 17 32 63");
    }
    else {
      // 辺の本数が最大のケース
      h = MaxH;
      w = MaxW;
      println(h, w);
      int cnt = 0, id = 1;
      for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
          cout << id;
          if(j != w - 1) cout << ' ';
          cnt++;
          if(cnt == 20) {
            cnt = 0;
            id++;
          }
        }
        cout << endl;
      }
    }
    return 0;
  }
  else if(namecontains("min")) {
    h = 1;
    w = 1;
  } else if(namecontains("max")) {
    h = MaxH;
    w = MaxW;
  } else {
    h = rnd.next(1, MaxH);
    w = rnd.next(1, MaxW);
  }
  println(h, w);

  map<int, int> cnt;
  for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        while(true) {
          // 適度に同じ数を生成させたいので下記のような生成方法
          int x = rnd.next(1, (rnd.next(0, 10) ? max(h*w / 20, 1) : MaxValue));
          if(cnt[x] < (namecontains("task1") ? 1 : 20)) {
            cnt[x]++;
            cout << x;
            if(j != w - 1) cout << ' ';
            break;
          }
        }
      }
      cout << endl;
  }

  return 0;
}
