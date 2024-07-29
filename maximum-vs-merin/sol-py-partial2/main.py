#!/usr/bin/env python3

def solve_grundy(n, damage, slimes):
    # ========== Grundy 数を O(max(H)^2) で求める解法 ========== #
    h_max = 0
    for h, _ in slimes:
        h_max = max(h_max, h)
    
    h_cnt = [0] * (h_max + 1)
    for h, c in slimes:
        h_cnt[h] += c

    grundy = [0] * (h_max + 1)
    for i in range(1, h_max + 1):
        s = set()
        for j in range(1, min(damage, i) + 1):
            s.add(grundy[i - j])
        for j in range(1, i // 2 + 1):
            s.add(grundy[j] ^ grundy[i - j])
        while grundy[i] in s:
            grundy[i] += 1

    ans = 0
    for i in range(h_max + 1):
        if h_cnt[i] % 2 == 0:
            continue
        ans ^= grundy[i]
    
    return "Maximum" if ans != 0 else "Merin"

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    damage = int(data[1])
    slimes = []

    index = 2
    for _ in range(n):
        h = int(data[index])
        c = int(data[index + 1])
        slimes.append((h, c))
        index += 2

    print(solve_grundy(n, damage, slimes))
