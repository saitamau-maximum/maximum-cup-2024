#!/usr/bin/python3

from sys import stdin

MOD = 998244353


def main():
    n, q = map(int, stdin.readline().split())
    for _ in range(q):
        i = int(stdin.readline())
        l = m = r = pow(3, MOD - 2, MOD)

        # L 伝播
        p1 = pow(3, n - i, MOD)
        x = m * (p1 - 1) * pow(2 * p1, MOD - 2, MOD) % MOD
        l = (l + x) % MOD
        m = (m - x + MOD) % MOD

        # R 伝播
        p2 = pow(3, i - 1, MOD)
        y = m * (p2 - 1) * pow(2 * p2, MOD - 2, MOD) % MOD
        r = (r + y) % MOD
        m = (m - y + MOD) % MOD

        print(l, m, r)


if __name__ == "__main__":
    main()
