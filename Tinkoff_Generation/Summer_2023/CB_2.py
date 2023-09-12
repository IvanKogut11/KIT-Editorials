def solve():
    n = int(input())
    if n == 0:
        print(0)
        return

    ans = []
    while n != 0:
        d = -(n // 2)

        ans.append(n - (-2) * d)
        n = d

    print(*reversed(ans), sep='')


if __name__ == '__main__':
    solve()

