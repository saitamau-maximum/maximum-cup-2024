#!/usr/bin/env python3

MAX_H = 1000
grundy = [0] * (MAX_H + 1)

def solve_grundy(slimes):
    ans = 0
    for h, c in slimes:
        if c % 2 == 0:
            continue
        ans ^= grundy[h]
    return "Maximum" if ans != 0 else "Merin"

def precompute_grundy(damage):
    tmp_mex = [0] * (2 * MAX_H)
    for i in range(1, MAX_H + 1):
        for j in range(1, min(damage, i) + 1):
            ele = grundy[i - j]
            if ele < 2 * MAX_H:
                tmp_mex[ele] = i
        for j in range(1, i // 2 + 1):
            ele = grundy[j] ^ grundy[i - j]
            if ele < 2 * MAX_H:
                tmp_mex[ele] = i
        while tmp_mex[grundy[i]] == i:
            grundy[i] += 1

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    q, damage = map(int, data[0].split())

    # Grundy 数の前計算
    precompute_grundy(damage)

    results = []
    idx = 1
    for _ in range(q):
        n = int(data[idx])
        slimes = []
        for i in range(n):
            h, c = map(int, data[idx + i + 1].split())
            slimes.append((h, c))
        results.append(solve_grundy(slimes))
        idx += n + 1

    print("\n".join(results))
