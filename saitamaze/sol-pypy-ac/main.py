#!/usr/bin/env pypy

import heapq
from sys import stdin

# 定数
INF = 10 ** 18

# 方向ベクトル
DIR_NUM = 4
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

# フィールド外判定関数
def outField(x, y, h, w):
    return not (0 <= x < h and 0 <= y < w)

def main():
    h, w = map(int, stdin.readline().split())
    x = [list(map(int, stdin.readline().split())) for i in range(h)]

    # 高さの圧縮
    comp = sorted(set(val for row in x for val in row))
    comp_map = {value: idx for idx, value in enumerate(comp)}
    group = [[] for _ in range(len(comp_map))]
    
    for i in range(h):
        for j in range(w):
            x[i][j] = comp_map[x[i][j]]
            group[x[i][j]].append((i, j))

    # 辺を列挙
    edges = [[[] for _ in range(w)] for _ in range(h)]
    for i in range(h):
        for j in range(w):
            # 同じ高さのマスに移動
            for ni, nj in group[x[i][j]]:
                if ni == i and nj == j:
                    continue
                cost = abs(ni - i) + abs(nj - j) - 1
                edges[i][j].append((cost, ni, nj))
            # 隣接マスに移動
            for dir in range(DIR_NUM):
                ni = i + dx[dir]
                nj = j + dy[dir]
                if outField(ni, nj, h, w) or x[i][j] == x[ni][nj]:
                    continue
                # 隣接マスの高さが異なる場合のみ追加
                edges[i][j].append((1, ni, nj))

    dist = [[INF] * w for _ in range(h)]
    dist[0][0] = 0
    pq = [(0, 0, 0)]  # (距離, i, j)
    
    while pq:
        d, i, j = heapq.heappop(pq)
        if i == h - 1 and j == w - 1:
            print(dist[h - 1][w - 1])
            return
        if dist[i][j] < d:
            continue
        for cost, ni, nj in edges[i][j]:
            if dist[ni][nj] <= d + cost:
                continue
            dist[ni][nj] = d + cost
            heapq.heappush(pq, (dist[ni][nj], ni, nj))

if __name__ == "__main__":
    main()
