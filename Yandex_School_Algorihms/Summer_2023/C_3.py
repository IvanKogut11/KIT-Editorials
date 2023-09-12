def solve():
    n = int(input())
    a = list(map(int, input().split()))
    cnt = {}
    max_cnt, max_cnt_ai = 0, 0
    for x in a:
        if x not in cnt:
            cnt[x] = 0
        cnt[x] += 1
        if cnt[x] > max_cnt:
            max_cnt = cnt[x]
            max_cnt_ai = x

    if max_cnt > (n + 1) // 2 or max_cnt == (n + 1) // 2 and max_cnt_ai != min(a):
        print("No")
    else:
        print("Yes")
    

if name == 'main':
    solve()
