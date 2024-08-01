#!/usr/bin/pypy

import sys


class WeightedDSU:
    def __init__(self, n):
        self._n = n
        self.parent_or_size = [-1] * n
        self.diff_weight = [0] * n

    def merge(self, a, b, w):
        w ^= self.weight(a)
        w ^= self.weight(b)

        x, y = self.leader(a), self.leader(b)
        if x == y:
            return x

        if -self.parent_or_size[x] < -self.parent_or_size[y]:
            x, y = y, x

        self.parent_or_size[x] += self.parent_or_size[y]
        self.parent_or_size[y] = x
        self.diff_weight[y] = w

        return x

    def same(self, a, b):
        return self.leader(a) == self.leader(b)

    def leader(self, a):
        if self.parent_or_size[a] < 0:
            return a
        r = self.leader(self.parent_or_size[a])
        self.diff_weight[a] ^= self.diff_weight[self.parent_or_size[a]]
        self.parent_or_size[a] = r
        return r

    def weight(self, x):
        self.leader(x)  # 経路圧縮
        return self.diff_weight[x]

    def diff(self, x, y):
        return self.weight(y) ^ self.weight(x)

def main():
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    n = int(data[index])
    q = int(data[index + 1])
    index += 2

    comp = []
    query = []
    
    for _ in range(q):
        t = int(data[index])
        L = int(data[index + 1])
        R = int(data[index + 2])
        l = -1
        r = -1
        index += 3
        if t == 1:
            l = int(data[index])
            r = int(data[index + 1])
            l -= 1
            r -= 1
            index += 2
        comp.extend([L, R])
        query.append((t, L, R, l, r))
    
    comp = sorted(set(comp))
    comp_map = {v: i for i, v in enumerate(comp)}
    masks = [((1 << i) - 1) for i in range(1, n + 1)]
    
    uf = WeightedDSU(len(comp))
    output = []
    
    for t, L, R, l, r in query:
        L = comp_map[L]
        R = comp_map[R]
        if t == 1:
            uf.merge(L, R, masks[r - l] << l)
        else:
            if not uf.same(L, R):
                output.append("Ambiguous")
            else:
                output.append(str(bin(uf.diff(L, R)).count('1')))
    
    print("\n".join(output))

if __name__ == "__main__":
    main()
