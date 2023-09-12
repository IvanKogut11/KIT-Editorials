def solve():
    n, a, b = map(int, input().split())
    t = [0] * n
    for i in range(n):
        h, m = map(int, input().split(':'))
        t[i] = 60 * h + m
    t.append(60 * 23 + 59)

    battery = 100
    for i in range(1, n + 1):
        d = t[i] - t[i - 1]
        if i % 2 != 0:
            battery = max(0., battery - (100. * d) / a)
        else:
            battery = min(100., battery + (100. * d) / b)

    print(f'{battery:.6f}')


if __name__ == "__main__":
    solve()

