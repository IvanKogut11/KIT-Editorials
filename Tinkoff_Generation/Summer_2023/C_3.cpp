#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const int INT_INF = (int)1e9 + 300;
const ll LL_INF = (ll)1e18 + (ll)300;

const int MAX_N = (int)1e6 + 10;

struct Segment {
    char c;
    int i_shift, j_shift;
};

bool is_in_rectangle(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Segment> segs = {
            {'/', -1, 1},
            {'\\', -1, -1},
            {'|', -1, 0},
            {'-', 0, -1}
    };
    int ans = 0;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < m; ++j) {
            for (auto seg : segs) {
                if (s[i][j] == seg.c && (!is_in_rectangle(i + seg.i_shift, j + seg.j_shift, n, m) || s[i + seg.i_shift][j + seg.j_shift] != seg.c)) {
                    ++ans;
                }
            }
        }
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
