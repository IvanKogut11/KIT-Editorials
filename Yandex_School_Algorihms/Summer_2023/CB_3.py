def solve():
    x, y, a, b, c = map(int, input().split())
    p = sorted(map(int, input().split()))
    q = sorted(map(int, input().split()))
    r = sorted(map(int, input().split()))

    ans = sum(p[a - x:]) + sum(q[b - y:])
    for i in range(c - 1, -1, -1):
        if x != 0 and (y == 0 or p[a - x] <= q[b - y]) and p[a - x] < r[i]:
            ans -= p[a - x]
            x -= 1
            ans += r[i]
        elif y != 0 and (x == 0 or q[b - y] <= p[a - x]) and q[b - y] < r[i]:
            ans -= q[b - y]
            y -= 1
            ans += r[i]
        else:
            break

    print(ans)


if __name__ == "__main__":
    solve()

