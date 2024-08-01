#!/usr/bin/env pypy3

import sys


class WeightedDSU:
    def __init__(self, n):
        self._n = n
        self.parent_or_size = [-1] * n
        self.diff_weight = [[False] * n for _ in range(n)]

    def merge(self, a, b, w):
        wa = self.weight(a)
        wb = self.weight(b)
        w_new = [wa[i] ^ wb[i] ^ w[i] for i in range(self._n)]

        x, y = self.leader(a), self.leader(b)
        if x == y:
            return x

        if -self.parent_or_size[x] < -self.parent_or_size[y]:
            x, y = y, x

        self.parent_or_size[x] += self.parent_or_size[y]
        self.parent_or_size[y] = x
        self.diff_weight[y] = w_new

        return x

    def same(self, a, b):
        return self.leader(a) == self.leader(b)

    def leader(self, a):
        if self.parent_or_size[a] < 0:
            return a
        r = self.leader(self.parent_or_size[a])
        for i in range(self._n):
            self.diff_weight[a][i] = self.diff_weight[a][i] ^ self.diff_weight[self.parent_or_size[a]][i]
        self.parent_or_size[a] = r
        return r

    def weight(self, x):
        self.leader(x)  # 経路圧縮
        return self.diff_weight[x]

    def diff(self, x, y):
        wx = self.weight(x)
        wy = self.weight(y)
        return [wx[i] ^ wy[i] for i in range(self._n)]

def generate_mask(n, l, r):
    mask = [False] * n
    for i in range(l, r + 1):
        mask[i] = True
    return mask

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
        l, r = -1, -1
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
    
    for i, (t, L, R, l, r) in enumerate(query):
        L = comp_map[L]
        R = comp_map[R]
        query[i] = (t, L, R, l, r)
    
    uf = WeightedDSU(len(comp))
    output = []
    
    for t, L, R, l, r in query:
        if t == 1:
            uf.merge(L, R, generate_mask(n, l, r))
        else:
            if uf.same(L, R):
                print(str(sum(uf.diff(L, R))))
            else:
                print("Ambiguous")
    
    print("\n".join(output))

if __name__ == "__main__":
    main()
