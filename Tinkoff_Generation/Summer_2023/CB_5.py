def solve():
    n, k, q = map(int, input().split())
    p = 0
    while 2**p < n:
        p += 1

    cnt = [0] * p
    for i in range(k):
        deg = int(input())
        cnt[deg] += 1

    for i in range(q):
        x = int(input())
        deg, l, r = p - 1, 1, n
        while l != r:
            mid = (l + r) // 2
            if x <= mid:
                d = x - l
                if cnt[deg] % 2 != 0:
                    x = mid + 1 + d
                    l = mid + 1
                else:
                    r = mid
            else:
                d = x - (mid + 1)
                if cnt[deg] % 2 != 0:
                    x = l + d
                    r = mid
                else:
                    l = mid + 1
            deg -= 1
        print(x)



if __name__ == '__main__':
    solve()

