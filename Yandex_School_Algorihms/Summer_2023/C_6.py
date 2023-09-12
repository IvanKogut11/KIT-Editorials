class Point:
    def init(self, x, y):
        self.x = x
        self.y = y


class Rectangle:
    def init(self, ld_p, ru_p):
        self.ld_p = ld_p
        self.ru_p = ru_p


def intersect(r1, r2):
    return Rectangle(
        Point(max(r1.ld_p.x, r2.ld_p.x), max(r1.ld_p.y, r2.ld_p.y)),
        Point(min(r1.ru_p.x, r2.ru_p.x), min(r1.ru_p.y, r2.ru_p.y))
    )


def solve():
    rects = []
    for i in range(4):
        ld_p_x, ld_p_y, ru_p_x, ru_p_y = map(int, input().split())
        rects.append(Rectangle(Point(ld_p_x, ld_p_y), Point(ru_p_x, ru_p_y)))

    ans = 0
    for mask in range(1, (1 << 4)):
        p = -1
        inter_rect = Rectangle(Point(-1000, -1000), Point(1000, 1000))
        for i in range(4):
            if mask & (1 << i):
                inter_rect = intersect(inter_rect, rects[i])
                p *= -1
        ans += p * max(0, inter_rect.ru_p.x - inter_rect.ld_p.x) * max(0, inter_rect.ru_p.y - inter_rect.ld_p.y)

    print(ans)


if __name__ == __"main"__:
    solve()

