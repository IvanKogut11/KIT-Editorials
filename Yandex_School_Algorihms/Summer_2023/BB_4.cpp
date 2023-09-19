#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

const ld EPS = 1e-4;
const int INT_INF = (int)2e9 + 10;
const ll LL_INF = (ll)1e18 + 3;

const int MAX_N = (int)1e5 + 10;
const int MAX_K = 20 + 1;

int dp[MAX_N][MAX_K][3];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<string> L = {"M", "P", "G"};
    for (int j = 0; j < 3; ++j) {
        dp[0][0][j] = L[j] == a[0];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= min(k, i); ++j) {
            for (int c_now = 0; c_now < 3; ++c_now) {
                for (int c_prev = 0; c_prev < 3; ++c_prev) {
                    int add = a[i] == L[c_now];
                    if (c_now != c_prev && j != 0) {
                        dp[i][j][c_now] = max(dp[i][j][c_now], dp[i - 1][j - 1][c_prev] + add);
                    } else if (c_now == c_prev) {
                        dp[i][j][c_now] = max(dp[i][j][c_now], dp[i - 1][j][c_prev] + add);
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= k; ++j) {
        for (int c = 0; c < 3; ++c) {
            ans = max(ans, dp[n - 1][j][c]);
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
