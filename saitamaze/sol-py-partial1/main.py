#!/usr/bin/env pypy

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    h = int(data[0])
    w = int(data[1])
    
    print(h + w - 2)

if __name__ == "__main__":
    main()
