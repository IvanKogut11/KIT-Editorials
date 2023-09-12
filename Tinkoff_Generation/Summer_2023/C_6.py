def solve():
    X, L = map(int, input().split())
    if L == 1:
        print(X+1)
        return

    ans = 10**18
    d = 2
    while True:
        dl = d ** L
        if dl > ans:
            break

        cur_ans = (X // dl + 1) * dl
        ans = min(ans, cur_ans)
        d += 1
    print(ans)


if __name__ == '__main__':
    solve()

