#!/usr/bin/env pypy

h, w = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(h)]
print(max([max(x) for x in a]))
