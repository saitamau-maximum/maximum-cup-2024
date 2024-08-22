#!/usr/bin/env pypy

from sys import stdin
import networkx as nx


def main():
    n, m = map(int, stdin.readline().split())
    c = list(map(int, stdin.readline().split()))
    G = nx.DiGraph()
    edges = []
    Graph = [[] for _ in range(n)]
    revGraph = [[] for _ in range(n)]
    G.add_nodes_from(range(n))
    for i in range(m):
        u, v, t = map(int, stdin.readline().split())
        G.add_edge(u - 1, v - 1, weight=t)
        Graph[u - 1].append(i)
        revGraph[v - 1].append(i)
        edges.append((u - 1, v - 1, t))

    if not nx.is_directed_acyclic_graph(G):
        print(-1)
        return

    ans = [0] * m
    for v in reversed(list(nx.topological_sort(G))):
        if len(revGraph[v]) > 0:
            eid = revGraph[v][0]
            ans[eid] = c[v]
            for eidx in Graph[v]:
                _v, u, t = edges[eidx]
                assert v == _v
                ans[eid] += ans[eidx]

    ansval = sum(ans[i] * edges[i][2] for i in range(m))
    print(ansval)


if __name__ == "__main__":
    main()
