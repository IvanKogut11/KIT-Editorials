def solve():
    n, m = map(int, input().split())
    t = input().split()
    q = input().split()
    d = list(map(int, input().split()))

    ans = 0
    for i in range(n):
        add = d[0]
        for j in range(m):
            if t[i] == q[j]:
                add = d[j + 1]
                break
        ans += add

    print(ans)


if __name__ == '__main__':
    solve()

