#!/usr/bin/env python3

import sys
from functools import lru_cache


def solve_dp(n, damage, slimes):
    h_max = 0
    for h, _ in slimes:
        h_max = max(h_max, h)

    h_cnt = [0] * (h_max + 1)
    for h, c in slimes:
        h_cnt[h] += c

    memo = {}

    def dfs():
        state = tuple(h_cnt)  # h_cntの状態をタプルに変換してセットに格納
        if state in memo:
            return memo[state]
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

        memo[state] = res
        return res

    return "Maximum" if dfs() else "Merin"

if __name__ == "__main__":
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

    result = solve_dp(n, damage, slimes)
    print(result)
