def solve():
    dirs = [
        (0, 1),
        (1, 0),
        (0, -1),
        (-1, 0)
    ]
    n = int(input())
    x, y = 0, 0
    speed, cur_dir = 0, 0
    for i in range(n):
        s = input()
        if s == "Stop":
            speed = 0
        elif speed == 0:
            if s == "Fwrd":
                speed = 100
            elif s == "Back":
                speed = -100
            elif s == "Rght":
                cur_dir = (cur_dir + 1) % 4
            elif s == "Left":
                cur_dir = (cur_dir - 1 + 4) % 4
        elif speed > 0:
            if s == "More":
                speed = min(speed + 100, 500)
            elif s == "Less":
                speed -= 100

        x += dirs[cur_dir][0] * speed
        y += dirs[cur_dir][1] * speed

    print(x, y)


if __name__ == '__main__':
    solve()

