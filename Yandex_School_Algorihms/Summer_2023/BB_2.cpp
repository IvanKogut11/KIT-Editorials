#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

const ld EPS = 1e-4;
const int INT_INF = (int)2e9 + 10;
const ll LL_INF = (ll)1e18 + 3;

const int MAX_N = (int)500 + 10;

int a[MAX_N][MAX_N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<pair<pair<int, int>, pair<int, int>>> ans, cur_ans;
    bool is_in_ans = false;
    for (int i = 0; i < n; ++i) {
        int st_j = i % 2 == 0 ? 0 : m - 1, end_j = i % 2 == 0 ? m : -1;
        int shift_j = i % 2 == 0 ? 1 : -1;

        for (int j = st_j; j != end_j; j += shift_j) {
            if (a[i][j] % 2) {
                if (is_in_ans) {
                    ans.insert(ans.end(), cur_ans.begin(), cur_ans.end());
                    is_in_ans = false;
                    cur_ans.clear();
                } else {
                    is_in_ans = true;
                }
            }

            if (is_in_ans && j + shift_j != end_j) {
                cur_ans.push_back({{i, j}, {i, j + shift_j}});
            }
        }
        if (is_in_ans && i != n - 1) {
            cur_ans.push_back({{i, end_j - shift_j}, {i + 1, end_j - shift_j}});
        }
    }

    cout << ans.size() << "\n";
    for (auto p : ans) {
        cout << p.first.first + 1 << " " << p.first.second + 1 << " " <<
                p.second.first + 1 << " " << p.second.second + 1 << "\n";
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
