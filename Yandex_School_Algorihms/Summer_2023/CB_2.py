right_numbers = []


def solve():
    x = int(input())
    l, r = -1, len(right_numbers)
    while r - l != 1:
        mid = (l + r) // 2
        if right_numbers[mid] <= x:
            l = mid
        else:
            r = mid

    if l == -1:
        print(-1)
    else:
        print(right_numbers[l])


def multitest():
    t = int(input())
    while t:
        solve()
        t -= 1


def precalc():
    for deg_1 in range(2, 62 + 1):
        for deg_2 in range(1, deg_1):
            for deg_3 in range(0, deg_2):
                right_numbers.append(2 ** deg_1 + 2 ** deg_2 + 2 ** deg_3)


if __name__ == "__main__":
    precalc()
    multitest()

