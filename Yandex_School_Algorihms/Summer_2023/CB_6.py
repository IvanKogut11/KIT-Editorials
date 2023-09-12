import copy


class Cake:
    def __init__(self, t, d, c):
        self.t = t
        self.d = d
        self.c = c

    def get_sum(self):
        return self.t + self.d + self.c


def get_ans(a, m, s_t, s_d, s_c):
    if m == 0:
        return 0

    for i in range(len(a)):
        a[i].t *= s_t
        a[i].d *= s_d
        a[i].c *= s_c

    sorted_a_sums = sorted(map(lambda x: x.get_sum(), a))
    return sum(sorted_a_sums[-m:])


def solve():
    n, m = map(int, input().split())
    a = [None] * n
    for i in range(n):
        a[i] = Cake(*map(int, input().split()))

    ans = 0
    for s_t in range(-1, 2, 2):
        for s_d in range(-1, 2, 2):
            for s_c in range(-1, 2, 2):
                ans = max(ans, get_ans(copy.deepcopy(a), m, s_t, s_d, s_c))

    print(ans)


if __name__ == "__main__":
    solve()

