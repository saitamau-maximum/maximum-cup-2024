#!/usr/bin/python3

from sys import stdin


def main():
    h, w = map(int, stdin.readline().split())
    print(h + w - 2)

if __name__ == "__main__":
    main()
