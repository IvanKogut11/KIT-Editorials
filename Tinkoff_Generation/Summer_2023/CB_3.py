def solve():
    n = int(input())
    ans = [
        "RGB",
        "GRB",
        "GBR",
        "BGR",
        "BRG",
        "RBG"
    ]
    print(ans[n % 6])


if __name__ == '__main__':
    solve()

