#!/usr/bin/env python3

MAX_H = 3000
grundy = [0] * (MAX_H + 1)

def solve_grundy(slimes):
    ans = 0
    for h, c in slimes:
        if c % 2 == 0:
            continue
        ans ^= grundy[h]
    
    return "Maximum" if ans != 0 else "Merin"

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    q = int(data[index])
    index += 1
    damage = int(data[index])
    index += 1
    
    # Grundy 数を前計算
    for i in range(1, MAX_H + 1):
        s = set()
        for j in range(1, min(damage, i) + 1):
            s.add(grundy[i - j])
        for j in range(1, i // 2 + 1):
            s.add(grundy[j] ^ grundy[i - j])
        while grundy[i] in s:
            grundy[i] += 1
    
    results = []
    
    for _ in range(q):
        n = int(data[index])
        index += 1
        
        slimes = []
        for i in range(n):
            h = int(data[index])
            c = int(data[index + 1])
            slimes.append((h, c))
            index += 2
        
        results.append(solve_grundy(slimes))

    for res in results:
        print(res)
