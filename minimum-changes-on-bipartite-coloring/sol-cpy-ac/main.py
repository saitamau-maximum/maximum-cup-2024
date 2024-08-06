#!/usr/bin/env python3

from sys import stdin
from atcoder.dsu import DSU


def main():
    n, m = map(int, stdin.readline().split())
    d = DSU(n)
    for _ in range(m):
        u, v = map(int, stdin.readline().split())
        d.merge(u - 1, v - 1)
    alpha = list(map(int, stdin.readline().split()))
    beta = list(map(int, stdin.readline().split()))

    cnt, cnt0, cnt1 = 0, 0, 0
    v01 = []
    v10 = []

    for i in range(n):
        if alpha[i] == beta[i]:
            if alpha[i] == 0:
                cnt0 += 1
            else:
                cnt1 += 1
        else:
            if alpha[i] == 0:
                v01.append(i)
            else:
                v10.append(i)
            cnt += 1
            if d.size(i) > 1:
                print(-1)
                return

    if cnt0 == 0 and cnt1 == 0 and len(v01) == 1 and len(v10) == 1:
        print(-1)
        return

    print(cnt)

    while len(v01) > 0 or len(v10) > 0:
        if cnt0 == 0 and cnt1 == 0:
            if len(v01) > 1:
                print(v01.pop() + 1, 1)
                cnt1 += 1
            else:
                print(v10.pop() + 1, 0)
                cnt0 += 1
        elif cnt0 == 0:
            print(v10.pop() + 1, 0)
            cnt0 += 1
        elif cnt1 == 0:
            print(v01.pop() + 1, 1)
            cnt1 += 1
        else:
            if len(v01) > 0:
                print(v01.pop() + 1, 1)
                cnt1 += 1
            if len(v10) > 0:
                print(v10.pop() + 1, 0)
                cnt0 += 1


if __name__ == "__main__":
    main()
