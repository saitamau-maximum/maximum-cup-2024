#!/usr/bin/python3

from sys import stdin
from collections import deque

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
    edges = [tuple(map(int, stdin.readline().split())) for _ in range(m)]

    ans = 0
    usedEdges = []
    d = DSU(n)
    for a, b, c in sorted(edges, key=lambda x: -x[2]):
        if not d.same(a - 1, b - 1):
            ans += c
            d.merge(a - 1, b - 1)
            usedEdges.append((a - 1, b - 1, c))
    edges = usedEdges
    del usedEdges

    Graph = [[] for _ in range(n)]
    for a, b, c in edges:
        Graph[a].append((b, c))
        Graph[b].append((a, c))

    log2n = n.bit_length()
    depth = [-1] * n
    par = [[-1] * log2n for _ in range(n)]
    minim = [[10**10] * log2n for _ in range(n)]

    que = deque()
    que.append(0)
    depth[0] = 0
    while que:
        v = que.popleft()
        for u, c in Graph[v]:
            if depth[u] == -1:
                depth[u] = depth[v] + 1
                par[u][0] = v
                minim[u][0] = c
                que.append(u)

    for k in range(log2n - 1):
        for v in range(n):
            if par[v][k] != -1:
                par[v][k + 1] = par[par[v][k]][k]
                minim[v][k + 1] = min(minim[v][k], minim[par[v][k]][k])

    def Query(x, y):
        if depth[x] < depth[y]:
            x, y = y, x
        res = 10**10
        t = depth[x] - depth[y]
        for k in range(log2n - 1, -1, -1):
            if t & (1 << k):
                res = min(res, minim[x][k])
                x = par[x][k]
        if x == y:
            return res
        for k in range(log2n - 1, -1, -1):
            if par[x][k] != par[y][k]:
                res = min(res, minim[x][k], minim[y][k])
                x = par[x][k]
                y = par[y][k]
        return min(res, minim[x][0], minim[y][0])

    q = int(stdin.readline())
    for _ in range(q):
        x, y, z = map(int, stdin.readline().split())
        res = Query(x - 1, y - 1)
        if res >= z:
            print(ans)
        else:
            print(ans - res + z)


if __name__ == "__main__":
    main()
