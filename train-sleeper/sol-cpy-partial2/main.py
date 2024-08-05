#!/usr/bin/python3

from sys import stdin

MOD = 998244353


def main():
    n, q = map(int, stdin.readline().split())

    dp = [
        [pow(3, MOD - 2, MOD), pow(3, MOD - 2, MOD), pow(3, MOD - 2, MOD)]
        for _ in range(n)
    ]
    # L 伝播
    for i in range(n - 2, -1, -1):
        x = dp[i][1] * dp[i + 1][0] % MOD
        dp[i][0] = (dp[i][0] + x) % MOD
        dp[i][1] = (dp[i][1] - x + MOD) % MOD
    # R 伝播
    for i in range(1, n):
        y = dp[i][1] * dp[i - 1][2] % MOD
        dp[i][2] = (dp[i][2] + y) % MOD
        dp[i][1] = (dp[i][1] - y + MOD) % MOD

    for _ in range(q):
        i = int(stdin.readline())
        i -= 1
        print(*dp[i])


if __name__ == "__main__":
    main()
