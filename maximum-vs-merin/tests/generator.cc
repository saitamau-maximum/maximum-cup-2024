#include "testlib.h"
#include <vector>
using namespace std;

// ファイル名に含まれるかどうか
#define namecontains(t) (filename.find(t) != string::npos)

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    const string filename = argv[1];

    // 問題に応じた最大値や制約を設定
    constexpr long long MaxH = 1'000'000'000;  // 1e9
    constexpr long long MaxC = 1'000'000'000;  // 1e9
    constexpr int MaxN = 200'000;              // 2e5
    constexpr int MaxD = 1'000'000'000;        // 1e9

    // 各タスクの最大値
    constexpr int Task1_MaxH = 30;
    constexpr int Task1_MaxC = 30;
    constexpr int Task2_MaxH = 3'000;

    int n;
    int d;
    long long maxH = MaxH;
    long long maxC = MaxC;

    if (namecontains("task1")) {
        // task 1 だけ ∑ H_i * C_i <= 30 という癖のある制約がある ⇒ 全部 hand で作成
        maxH = Task1_MaxH;
        maxC = Task1_MaxC;
        if (namecontains("hand00")) {
            n = 1;
            d = MaxD;
            println(n, d);
            println(maxH, 1);
            // Maximum 勝利
        } else if (namecontains("hand01")) {
            n = 1;
            d = 1;
            println(n, d);
            println(1, 1);
            // sum = 1 * 1 = 1
            // Maximum 勝利
        } else if (namecontains("hand02")) {
            n = 3;
            d = 3;
            println(n, d);
            println(1, 1); // 1 * 1
            println(2, 1); // 2 * 1
            println(4, 1); // 3 * 1
            // sum = 1 * 1 + 2 * 1 + 4 * 1 = 1 + 2 + 4 = 7
            // Merin 勝利
        }
        else if (namecontains("hand03")) {
            n = 5;
            d = 2;
            println(n, d);
            println(1, 4); // 1 * 4
            println(3, 1); // 3 * 1
            println(5, 1); // 5 * 1
            println(7, 1); // 7 * 1
            println(9, 1); // 9 * 1
            // sum = 1 * 4 + 3 * 1 + 5 * 1 + 7 * 1 + 9 * 1 = 4 + 3 + 5 + 7 + 9 = 28
            // Merin 勝利
        }
        else if (namecontains("hand04")) {
            n = 7;
            d = 998244353;
            println(n, d);
            println(1, 1); // 1 * 1
            println(2, 1); // 2 * 1
            println(3, 1); // 3 * 1
            println(4, 1); // 4 * 1 
            println(5, 1); // 5 * 1
            println(6, 1); // 6 * 1
            println(7, 1); // 7 * 1
            // sum = 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28
            // Maximum 勝利
        }
        else if (namecontains("hand05")) {
            n = 3;
            d = 10;
            println(n, d);
            println(3, 1); // 3 * 1
            println(12, 1); // 12 * 1
            println(15, 1); // 15 * 1
            // sum = 3 + 12 + 15 = 30
            // Maximum 勝利
        }
        else {
            cerr << "Invalid filename: " << filename << endl;
            return 1;
        }
        return 0;
    } else if (namecontains("task2")) {
        maxH = Task2_MaxH;
        if (namecontains("max")) {
            n = MaxN;
            d = MaxD;
        } else if (namecontains("min")) {
            n = 1;
            d = 1;
        } else {
            // random はほぼ全部 Maximum が勝ちそうなので hand は全て Merin 勝利になるように設定
            if (namecontains("hand00")) {
                n = MaxN;
                d = 1234;
                println(n, d);
                for (int i = 1; i <= n; ++i) {
                    println(rnd.next(1LL, maxH), rnd.next(1LL, maxC / 4) * 2);
                }
                // 全部偶数で Merin 勝利パターン
                return 0;
            }
            else if (namecontains("hand01")) {
                n = 9;
                d = 87;
                println(n, d);
                println(2485 ,836079998);
                println(2913 ,963280210);
                println(715 ,589648714);
                println(1839 ,534429842);
                println(1952 ,820248911);
                println(1023 ,727550052);
                println(2998 ,438405271);
                println(12 ,3);
                println(90 ,19);
                // Merin 勝利パターン 1
                return 0;
            }
            else if (namecontains("hand02")) {
                n = 11;
                d = 438;
                println(n, d);
                println(1035, 672813920);
                println(2457, 184920671);
                println(2999, 573820194);
                println(1508, 890712345);
                println(2341, 128390472);
                println(762, 902817364);
                println(1884, 342718293);
                println(2992, 748291036);
                println(1801, 918273645);
                println(2793, 465738291);
                println(369, 123839291);
                // Merin 勝利パターン 2
                return 0;
            }
            else if (namecontains("hand03")) {
                n = 21;
                d = 1895732;
                println(n, d);
                println(2485, 836079998);
                println(2913, 963280210);
                println(715, 589648714);
                println(1839, 534429842);
                println(1952, 820248911);
                println(1023, 727550052);
                println(2998, 438405271);
                println(1527, 856379210);
                println(2301, 472890145);
                println(1246, 918273645);
                println(867, 102938475);
                println(2990, 203847561);
                println(1783, 564738291);
                println(2921, 987654321);
                println(1456, 123456789);
                println(2817, 456789012);
                println(914, 678901234);
                println(2753, 876543210);
                println(1065, 234567890);
                println(2996, 345678901);
                println(2893, 489174199);
                // Merin 勝利パターン 3
                return 0;
            }
            else if (namecontains("hand")) {
                cerr << "Invalid filename: " << filename << endl;
                return 1;
            }
            n = rnd.next(1, MaxN);
            d = rnd.next(1, MaxD);
        }
    } else {
        if (namecontains("max")) {
            n = MaxN;
            d = MaxD;
        } else if (namecontains("min")) {
            n = 1;
            d = 1;
        } else {
            // random はほぼ全部 Maximum が勝ちそうなので hand は全て Merin 勝利になるように設定
            if (namecontains("hand00")) {
                n = MaxN;
                d = 1234567;
                println(n, d);
                for (int i = 1; i <= n; ++i) {
                    println(rnd.next(1LL, maxH), rnd.next(1LL, maxC / 4) * 2);
                }
                // 全部偶数で Merin 勝利パターン
                return 0;
            }
            else if (namecontains("hand01")) {
                n = 7;
                d = 432897;
                println(n, d);
                println(836079998, 963280210);
                println(589648714, 534429842);
                println(820248911, 727550052);
                println(438405271, 505204932);
                println(160331424, 942311677);
                println(770205701, 182932473);
                println(218278, 74389273); // 調整用スライム（hand 生成が難しいので）
                // Merin 勝利パターン 1
                return 0;
            }
            else if (namecontains("hand02")) {
                n = 11;
                d = 7654321;
                println(n, d);
                println(589473012, 453678321);
                println(794231456, 286795432);
                println(912345678, 123456789);
                println(657489123, 874561234);
                println(234567890, 987654321);
                println(134567890, 876543210);
                println(456789012, 678901234);
                println(345678901, 765432109);
                println(223456789, 987612345);
                println(5827602, 37289); // 調整用スライム
                println(1, 48302851); // 調整用スライム
                // Merin 勝利パターン 2
                return 0;
            }
            else if (namecontains("hand03")) {
                n = 21;
                d = 86732569;
                println(n, d);
                println(502634415, 800310983);
                println(430071672, 409710892);
                println(760313542, 968221089);
                println(217345012, 112030456);
                println(834123764, 987654123);
                println(345678123, 654321789);
                println(715233907, 230981654);
                println(489123567, 567890432);
                println(987654123, 234567890);
                println(111222333, 444555666);
                println(765432198, 876543211);
                println(345678901, 765432109);
                println(567890123, 234567890);
                println(909812345, 102938475);
                println(120394857, 908172635);
                println(674829104, 387492018);
                println(502918374, 291837465);
                println(192837465, 647382913);
                println(938471029, 102983741);
                println(829103847, 293847121);
                println(63589293, 85766879); // 調整用スライム
                // Merin 勝利パターン 3
                return 0;
            }
            else if (namecontains("hand")) {
                cerr << "Invalid filename: " << filename << endl;
                return 1;
            }
            n = rnd.next(1, MaxN);
            d = rnd.next(1, MaxD);
        }
    }

    vector<pair<long long, long long>> slimes(n);
    for (int i = 0; i < n; ++i) {
        slimes[i].first = rnd.next(1LL, maxH);
        slimes[i].second = rnd.next(1LL, maxC);
    }

    // 出力
    println(n, d);
    for (const auto &slime : slimes) {
        println(slime.first, slime.second);
    }

    return 0;
}
