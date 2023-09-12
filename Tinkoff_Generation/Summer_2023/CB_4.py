def calc(f):
    ans = 0
    for p in range(32):
        ans += (f // (2**p)) * 2**p
    return ans


def solve():
    p, q = map(int, input().split())
    ans = calc(q) - calc(p - 1)
    print(ans)


if __name__ == '__main__':
    solve()

