#!/usr/bin/python3

import networkx as nx
from sys import stdin


def popcount(n):
    c = (n & 0x5555555555555555) + ((n >> 1) & 0x5555555555555555)
    c = (c & 0x3333333333333333) + ((c >> 2) & 0x3333333333333333)
    c = (c & 0x0F0F0F0F0F0F0F0F) + ((c >> 4) & 0x0F0F0F0F0F0F0F0F)
    c = (c & 0x00FF00FF00FF00FF) + ((c >> 8) & 0x00FF00FF00FF00FF)
    c = (c & 0x0000FFFF0000FFFF) + ((c >> 16) & 0x0000FFFF0000FFFF)
    c = (c & 0x00000000FFFFFFFF) + ((c >> 32) & 0x00000000FFFFFFFF)
    return c


def main():
    n, m = map(int, stdin.readline().split())
    baseG = [[] for i in range(n)]
    for _ in range(m):
        u, v = map(int, stdin.readline().split())
        u -= 1
        v -= 1
        baseG[u].append(v)
        baseG[v].append(u)

    alphaVec = list(map(int, stdin.readline().split()))
    betaVec = list(map(int, stdin.readline().split()))

    alpha = sum(a << i for i, a in enumerate(alphaVec))
    beta = sum(b << i for i, b in enumerate(betaVec))

    goodColoring = []
    for S in range(1 << n):
        if S == 0 or S == (1 << n) - 1:
            continue
        ok = True
        for i in range(n):
            for j in baseG[i]:
                if (S >> i & 1) == (S >> j & 1):
                    ok = False
        if ok:
            goodColoring.append(S)

    G = nx.Graph()
    G.add_nodes_from(range(1 << n))

    for S in goodColoring:
        for T in goodColoring:
            if S == T:
                continue
            if popcount(S ^ T) == 1:
                G.add_edge(S, T)

    if nx.has_path(G, alpha, beta):
        path = nx.shortest_path(G, alpha, beta)
        print(len(path) - 1)
        for i in range(len(path) - 1):
            x = path[i + 1] ^ path[i]
            for j in range(n):
                if x >> j & 1:
                    print(j + 1, path[i + 1] >> j & 1)

    else:
        print(-1)


if __name__ == "__main__":
    main()
