#!/usr/bin/python3

n = int(input())
a = set(list(map(int, input().split())))

s = set()

for x in a:
  for y in a:
    for z in a:
      s.add(x + y + z)

print(len(s))
