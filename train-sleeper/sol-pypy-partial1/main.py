#!/usr/bin/env pypy

from sys import stdin

MOD = 998244353


def main():
    n, q = map(int, stdin.readline().split())

    ans = [[0, 0, 0] for _ in range(n)]
    for state in range(pow(3, n)):
        stateVec = [state // pow(3, i) % 3 for i in range(n)]

        # L 伝播
        for i in range(n - 2, -1, -1):
            if stateVec[i] == 1 and stateVec[i + 1] == 0:
                stateVec[i] = 0

        # R 伝播
        for i in range(1, n):
            if stateVec[i] == 1 and stateVec[i - 1] == 2:
                stateVec[i] = 2

        for i in range(n):
            ans[i][stateVec[i]] += 1

    for i in range(n):
        for j in range(3):
            ans[i][j] = ans[i][j] * pow(pow(3, n), MOD - 2, MOD) % MOD

    for _ in range(q):
        i = int(stdin.readline())
        i -= 1
        print(*ans[i])


if __name__ == "__main__":
    main()
