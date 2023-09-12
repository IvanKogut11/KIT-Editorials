import heapq


def solve():
    n, m = map(int, input().split())
    c = sorted(map(int, input().split()))

    l = map(int, input().split())
    d = map(int, input().split())
    l_d = sorted(zip(l, d))

    h = []
    j = 0
    ans = 0
    for i in range(n):
        ans += c[i]
        while j < m and l_d[j][0] <= c[i]:
            heapq.heappush(h, -l_d[j][1])
            j += 1
        if h:
            ans -= -heapq.heappop(h)

    print(ans)


if __name__ == "__main__":
    solve()

