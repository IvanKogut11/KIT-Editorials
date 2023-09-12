#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const int INT_INF = (int)1e9 + 300;
const ll LL_INF = (ll)1e18 + (ll)300;

const int MAX_N = (int)1e6 + 10;

struct Point {
    int x, y;
};

struct Rectangle {
    Point ld_p, ru_p;
};

Rectangle intersect(const Rectangle& r1, const Rectangle& r2) {
    return {{max(r1.ld_p.x, r2.ld_p.x), max(r1.ld_p.y, r2.ld_p.y)}, {min(r1.ru_p.x, r2.ru_p.x), min(r1.ru_p.y, r2.ru_p.y)}};
}

void solve() {
    vector<Rectangle> rects(4);
    for (int i = 0; i < 4; ++i) {
        cin >> rects[i].ld_p.x >> rects[i].ld_p.y >> rects[i].ru_p.x >> rects[i].ru_p.y;
    }

    int ans = 0;
    for (int mask = 1; mask < (1 << 4); ++mask) {
        Rectangle inter_rect = {{-1000, -1000}, {1000, 1000}};
        int p = -1;
        for (int i = 0; i < 4; ++i) {
            if (mask & (1 << i)) {
                inter_rect = intersect(inter_rect, rects[i]);
                p *= -1;
            }
        }

        ans += p * max(0, inter_rect.ru_p.x - inter_rect.ld_p.x) * max(0, inter_rect.ru_p.y - inter_rect.ld_p.y);
    }

    cout << ans;
}

void multitest() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //multitest();
    solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}
