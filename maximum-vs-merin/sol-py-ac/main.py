#!/usr/bin/env python3

def solve_grundy_fast(n, damage, slimes):
    def grundy(x, d):
        if x == 0:
            return 0
        x -= 1

        T1 = d + d % 2
        if x < T1:
            res = x
            if x % 4 == 2:
                res += 1
            elif x % 4 == 3:
                res -= 1
            return res + 1

        x -= T1
        T2 = d + 2 - d % 2
        if d % 2 == 0:
            if x % T2 == 0:
                return 0
            elif x % T2 == 1:
                return d + 1
            else:
                res = x % T2 - 2
                if res % 4 == 2:
                    res += 1
                elif res % 4 == 3:
                    res -= 1
                return res + 1
        else:
            if x % T2 == 0:
                return 0
            else:
                res = x % T2 - 1
                if res % 4 == 0:
                    res += 1
                elif res % 4 == 1:
                    res -= 1
                return res + 1

    total_grundy = 0
    for h, c in slimes:
        if c % 2 == 0:
            continue
        total_grundy ^= grundy(h, damage)

    return "Maximum" if total_grundy != 0 else "Merin"

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    index = 0
    q = int(data[index])
    index += 1
    
    results = []
    
    for _ in range(q):
        n = int(data[index])
        damage = int(data[index + 1])
        index += 2
        
        slimes = []
        for i in range(n):
            h = int(data[index])
            c = int(data[index + 1])
            slimes.append((h, c))
            index += 2
        
        results.append(solve_grundy_fast(n, damage, slimes))

    for res in results:
        print(res)
