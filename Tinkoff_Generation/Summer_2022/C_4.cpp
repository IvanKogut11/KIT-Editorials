#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const int INT_INF = (int)1e9 + 300;
const ll LL_INF = (ll)1e18 + (ll)300;

const int MAX_N = (int)1e6 + 10;

void solve() {
    vector<int> v(5);
    for (int i = 0; i < 5; ++i) {
        cin >> v[i];
    }
    int K;
    cin >> K;

    vector<vector<int>> add = {
            {0, 0, 1},
            {0, 0, 1},
            {0, 1, 0},
            {1, 0, 0},
            {1, 1, 0}
    };
    vector<int> ans(3, 0);

    for (int i = 0; K > 0; ++i) {
        int cnt = min(K, v[i % 5]);
        K -= cnt;
        for (int j = 0; j < 3; ++j) {
            if (i % 5 == 1) {
                ans[j] += add[i % 5][j] * (cnt + 1) / 2;
            } else {
                ans[j] += add[i % 5][j] * cnt;
            }
        }
    }

    for (int x : ans) {
        cout << x << " ";
    }
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
