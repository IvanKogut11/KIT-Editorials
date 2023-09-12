def calc_off_days_to_use(l, r, w, is_off_day):
    off_days_to_use = 0
    c = 1
    for d in range(l, r + 1):
        if (d + w) % 7 >= 5:
            off_days_to_use += 1
        if is_off_day[d]:
            c = 1
            continue
        if c == 7:
            off_days_to_use -= 1
            c = 1
            continue
        c += 1
    return off_days_to_use


def check(ans, days_cnt, w, is_off_day):
    for l in range(0, days_cnt - ans + 1):
        r = l + ans - 1
        off_days_to_use = 0
        off_days_to_use += calc_off_days_to_use(0, l - 1, w, is_off_day)
        off_days_to_use += calc_off_days_to_use(r + 1, days_cnt - 1, w, is_off_day)
        for i in range(l, r + 1):
            off_days_to_use += (w + i) % 7 >= 5
            off_days_to_use += is_off_day[i]
        if r - l + 1 <= off_days_to_use:
            return True

    return False


def solve():
    y, w = map(int, input().split())
    w -= 1
    days = [
        31, 28, 31, 30,
        31, 30, 31, 31,
        30, 31, 30, 31
    ]
    days[1] += y % 4 == 0
    days_cnt = 365 + (y % 4 == 0)

    n = int(input())
    is_off_day = [False] * days_cnt
    for i in range(n):
        d, m = map(int, input().split('.'))
        day = d - 1
        for j in range(m - 1):
            day += days[j]
        is_off_day[day] = True

    bin_l, bin_r = 0, days_cnt + 1
    while bin_r - bin_l != 1:
        mid = (bin_l + bin_r) // 2
        if check(mid, days_cnt, w, is_off_day):
            bin_l = mid
        else:
            bin_r = mid

    print(bin_l)


if __name__ == '__main__':
    solve()

