def solve():
    n = int(input())
    for i in range(n):
        for j in range(n):
            if i == n - j - 1:
                print(1, end='')
            elif i < n - j - 1:
                print(0, end='')
            else:
                print(2, end='')
        print()


if __name__ == '__main__':
    solve()

