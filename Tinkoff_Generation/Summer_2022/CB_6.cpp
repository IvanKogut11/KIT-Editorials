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
    int n;
    cin >> n;

    vector<pair<int, vector<vector<int>>>> v = {
            {0, {{}, {}, {}}},
            {-1, {}},
            {8, {{8, 4}, {7, 3, 2}, {6, 5, 1}}},
            {9, {{9, 5, 1}, {8, 4, 3}, {7, 6, 2}}},
            {-1, {}},
            {5, {{5}, {4, 1}, {3, 2}}}
    };

    int st = v[n % 6].first;
    if (st == -1 || n < st) {
        cout << -1;
        return;
    }

    vector<vector<int>> ans = v[n % 6].second;
    for (int i = st; i < n; i += 6) {
        for (int j = 0; j < 3; ++j) {
            ans[j].push_back(i + j + 1);
            ans[j].push_back(i + 6 - j);
        }
    }

    for (int i = 0; i < 3; ++i) {
        cout << ans[i].size() << "\n";
        for (int x : ans[i]) {
            cout << x << " ";
        }
        cout << "\n\n";
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
