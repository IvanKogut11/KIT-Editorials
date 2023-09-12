import heapq


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    pos = [0] * n
    for i in range(n):
        pos[a[i] - 1] = i

    b = list(map(int, input().split()))
    for i in range(n):
        a[pos[b[i] - 1]] = i

    ans = 0
    h = []
    for x in a:
        if len(h) != 0 and -h[0] > x:
            ans += 1
        heapq.heappush(h, -x)

    print(ans)


if __name__ == "__main__":
    solve()

