#!/usr/bin/env pypy

from sys import stdin
import networkx as nx


def main():
    n, m = map(int, stdin.readline().split())
    c = list(map(int, stdin.readline().split()))
    G = nx.DiGraph()
    G.add_nodes_from(range(n))
    for _ in range(m):
        u, v, t = map(int, stdin.readline().split())
        G.add_edge(u - 1, v - 1, weight=t)

    if not nx.is_directed_acyclic_graph(G):
        print(-1)
        return

    ans = [0] * n
    for v in nx.topological_sort(G):
        for u in G.predecessors(v):
            ans[v] = max(ans[v], ans[u] + G[u][v]["weight"])

    ansval = sum(ans[i] * c[i] for i in range(n))
    print(ansval)


if __name__ == "__main__":
    main()
