#!/usr/bin/env python3

from collections import defaultdict
from functools import lru_cache


def solve_dp(n, damage, slimes):
    h_max = 0
    for h, c in slimes:
        h_max = max(h_max, h)

    h_cnt = [0] * (h_max + 1)
    for h, c in slimes:
        h_cnt[h] = c

    memo = {}

    def dfs():
        h_cnt_tuple = tuple(h_cnt)
        if h_cnt_tuple in memo:
            return memo[h_cnt_tuple]
        res = False

        # 分割遷移
        for i in range(2, h_max + 1):
            if h_cnt[i] == 0:
                continue
            h_cnt[i] -= 1
            for j in range(1, i // 2 + 1):
                h_cnt[j] += 1
                h_cnt[i - j] += 1
                res |= not dfs()
                h_cnt[j] -= 1
                h_cnt[i - j] -= 1
                if res:
                    break
            h_cnt[i] += 1
            if res:
                break

        # 消費遷移
        if not res:
            for i in range(1, h_max + 1):
                if h_cnt[i] == 0:
                    continue
                h_cnt[i] -= 1
                for j in range(1, min(damage, i) + 1):
                    if i - j != 0:
                        h_cnt[i - j] += 1
                    res |= not dfs()
                    if i - j != 0:
                        h_cnt[i - j] -= 1
                    if res:
                        break
                h_cnt[i] += 1
                if res:
                    break

        memo[h_cnt_tuple] = res
        return res

    return "Maximum" if dfs() else "Merin"

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    q, damage = map(int, data[0].split())
    results = []
    for i in range(1, q + 1):
        n = int(data[2 * i - 1])
        slimes = []
        for j in range(n):
            h, c = map(int, data[2 * i + j].split())
            slimes.append((h, c))
        results.append(solve_dp(n, damage, slimes))

    print("\n".join(results))
