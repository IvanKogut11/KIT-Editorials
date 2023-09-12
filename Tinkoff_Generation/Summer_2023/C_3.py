def is_in_rectangle(i, j, n, m):
    return 0 <= i < n and 0 <= j < m


def solve():
    n, m = map(int, input().split())
    segs = {
        '/': (-1, 1),
        '\\': (-1, -1),
        '|': (-1, 0),
        '-': (0, -1)
    }
    s = []
    ans = 0
    for i in range(n):
        s.append(input())
        for j in range(m):
            if s[i][j] not in segs:
                continue
            if not is_in_rectangle(i + segs[s[i][j]][0], j + + segs[s[i][j]][1], n, m) or s[i + segs[s[i][j]][0]][j + segs[s[i][j]][1]] != s[i][j]:
                ans += 1
    print(ans)


if __name__ == '__main__':
    solve()

