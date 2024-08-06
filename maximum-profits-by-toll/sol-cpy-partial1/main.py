#!/usr/bin/env python3

from sys import stdin
import networkx as nx


def main():
    n, m = map(int, stdin.readline().split())
    c = list(map(int, stdin.readline().split()))
    G = nx.DiGraph()
    G.add_nodes_from(range(n))
    for _ in range(m):
        u, v, h = map(int, stdin.readline().split())
        G.add_edge(u - 1, v - 1, weight=h)

    print(0 if nx.is_directed_acyclic_graph(G) else -1)


if __name__ == "__main__":
    main()
