#!/usr/bin/python3

import heapq
from collections import defaultdict

# 定数
INF = float('inf')

# 方向ベクトル
DIR_NUM = 4
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

# フィールド外判定関数
def outField(x, y, h, w):
    return not (0 <= x < h and 0 <= y < w)

def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    h = int(data[0])
    w = int(data[1])
    x = []
    index = 2
    for i in range(h):
        row = []
        for j in range(w):
            value = int(data[index])
            row.append(value)
            index += 1
        x.append(row)
    
    # 高さの圧縮を効率化するための辞書を使用
    comp = sorted(set(val for row in x for val in row))
    comp_map = {value: idx for idx, value in enumerate(comp)}
    group = defaultdict(list)
    
    for i in range(h):
        for j in range(w):
            x[i][j] = comp_map[x[i][j]]
            group[x[i][j]].append((i, j))
    
    dist = [[INF] * w for _ in range(h)]
    dist[0][0] = 0
    pq = [(0, 0, 0)]  # (距離, i, j)
    
    while pq:
        d, i, j = heapq.heappop(pq)
        if dist[i][j] < d:
            continue
        # 同じ高さのマスに移動
        for ni, nj in group[x[i][j]]:
            if ni == i and nj == j:
                continue
            cost = d + abs(ni - i) + abs(nj - j) - 1
            if dist[ni][nj] > cost:
                dist[ni][nj] = cost
                heapq.heappush(pq, (cost, ni, nj))
        # 隣接マスに移動
        for dir in range(DIR_NUM):
            ni = i + dx[dir]
            nj = j + dy[dir]
            if outField(ni, nj, h, w):
                continue
            nd = d + 1
            if dist[ni][nj] > nd:
                dist[ni][nj] = nd
                heapq.heappush(pq, (nd, ni, nj))
    
    print(dist[h - 1][w - 1])

if __name__ == "__main__":
    main()
