def solve():
    k = int(input())
    s = input()

    as_first_char_pos = []
    for i in range(1, k):
        if s[i] > s[0]:
            print("Yes")
            return
        if s[i] == s[0]:
            as_first_char_pos.append(i)

    for pos in as_first_char_pos:
        if s[:pos] < s[pos:]:
            print("Yes")
            return

    print("No")


def multitest():
    t = int(input())
    while t:
        solve()
        t -= 1


if __name__ == '__main__':
    multitest()
    # solve()

