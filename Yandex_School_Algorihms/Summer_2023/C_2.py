def solve():
    a, b = map(int, input().split())
    if a > b:
        a, b = b, a
    ans = 0
    while a != 0:
        ans += b // a
        b %= a
        a, b = b, a
    ans -= 1
    print(ans)


if __name__ == '__main__':
    solve()

