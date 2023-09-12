def solve():
    h, m = map(int, input().split())
    print((12 - h) % 12, (60 - m) % 60)


if __name__ == '__main__':
    solve()

