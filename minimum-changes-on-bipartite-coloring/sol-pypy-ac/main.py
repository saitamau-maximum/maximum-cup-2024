#!/usr/bin/env pypy

from sys import stdin

import typing


# ac-library python
class DSU:
    """
    Implement (union by size) + (path halving)

    Reference:
    Zvi Galil and Giuseppe F. Italiano,
    Data structures and algorithms for disjoint set union problems
    """

    def __init__(self, n: int = 0) -> None:
        self._n = n
        self.parent_or_size = [-1] * n

    def merge(self, a: int, b: int) -> int:
        assert 0 <= a < self._n
        assert 0 <= b < self._n

        x = self.leader(a)
        y = self.leader(b)

        if x == y:
            return x

        if -self.parent_or_size[x] < -self.parent_or_size[y]:
            x, y = y, x

        self.parent_or_size[x] += self.parent_or_size[y]
        self.parent_or_size[y] = x

        return x

    def same(self, a: int, b: int) -> bool:
        assert 0 <= a < self._n
        assert 0 <= b < self._n

        return self.leader(a) == self.leader(b)

    def leader(self, a: int) -> int:
        assert 0 <= a < self._n

        parent = self.parent_or_size[a]
        while parent >= 0:
            if self.parent_or_size[parent] < 0:
                return parent
            self.parent_or_size[a], a, parent = (
                self.parent_or_size[parent],
                self.parent_or_size[parent],
                self.parent_or_size[self.parent_or_size[parent]],
            )

        return a

    def size(self, a: int) -> int:
        assert 0 <= a < self._n

        return -self.parent_or_size[self.leader(a)]

    def groups(self) -> typing.List[typing.List[int]]:
        leader_buf = [self.leader(i) for i in range(self._n)]

        result: typing.List[typing.List[int]] = [[] for _ in range(self._n)]
        for i in range(self._n):
            result[leader_buf[i]].append(i)

        return list(filter(lambda r: r, result))


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
