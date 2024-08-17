#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    // 1 <= Q <= 2e5
    int Q = inf.readInt(1, 200000, "Q");
    inf.readSpace();
    // 1 <= D <= 1e9
    int D = inf.readInt(1, 1000000000, format("D"));
    inf.readEoln();

    long long totalN = 0;

    for (int i = 0; i < Q; ++i) {
        // 1 <= N <= 2e5
        int N = inf.readInt(1, 200000, format("N[%d]", i));
        inf.readEoln();

        totalN += N;
        ensuref(totalN <= 200000, "Sum of all N should not exceed 200000");

        for (int j = 0; j < N; ++j) {
            // 1 <= H_j <= 1e9
            long long H = inf.readLong(1LL, 1000000000LL, format("H[%d,%d]", i, j));
            inf.readSpace();
            // 1 <= C_j <= 1e9
            long long C = inf.readLong(1LL, 1000000000LL, format("C[%d,%d]", i, j));
            inf.readEoln();  // 各行の終わりに改行
        }
    }

    inf.readEof();  // EOF
}
