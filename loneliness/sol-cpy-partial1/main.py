#!/usr/bin/python3

import sys
from collections import deque


def main():
    input = sys.stdin.read
    data = input().split()
    
    q = int(data[0])
    index = 1
    
    comp = []
    query = []
    
    for _ in range(q):
        t = int(data[index])
        L = int(data[index + 1])
        R = int(data[index + 2])
        l, r = -1, -1
        index += 3
        if t == 1:
            l = int(data[index])
            r = int(data[index + 1])
            index += 2
        comp.extend([L, R])
        query.append((t, L, R, l, r))
    
    comp = sorted(set(comp))
    comp_map = {v: i for i, v in enumerate(comp)}
    
    for i, (t, L, R, l, r) in enumerate(query):
        L = comp_map[L]
        R = comp_map[R]
        query[i] = (t, L, R, l, r)
    
    Graph = [[] for _ in range(len(comp))]
    for t, L, R, l, r in query:
        if t == 1:
            Graph[L].append((R, l, r))
            Graph[R].append((L, l, r))
        else:
            visited = [False] * len(comp)
            que = deque([(L, [0] * 60)])
            
            arrived = False
            while que:
                now, bit = que.popleft()
                if now == R:
                    print(sum(bit))
                    arrived = True
                    break
                if visited[now]:
                    continue
                visited[now] = True
                for to, nl, nr in Graph[now]:
                    if visited[to]:
                        continue
                    new_bit = bit[:]
                    for i in range(nl - 1, nr):
                        new_bit[i] ^= 1
                    que.append((to, new_bit))
            if not arrived:
                print("Ambiguous")

if __name__ == "__main__":
    main()
