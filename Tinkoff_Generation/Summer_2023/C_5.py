def solve():
    s = input()
    n = len(s)
    ans = ""
    for i in range(n - 1):
        if s[i] == s[i + 1] and (not ans or ans > s[i:i+2]):
            ans = s[i:i+2]
    if ans:
        print(ans)
        return

    for i in range(n - 2):
        if s[i] == s[i + 2] and (not ans or ans > s[i:i+3]):
            ans = s[i:i+3]
    if ans:
        print(ans)
        return

    print(-1)


if __name__ == '__main__':
    solve()

