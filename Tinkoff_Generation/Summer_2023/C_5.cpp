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
    string s;
    cin >> s;
    int n = s.size();

    string ans = "";
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1] && (ans.empty() || ans > s.substr(i, 2))) {
            ans = s.substr(i, 2);
        }
    }
    if (!ans.empty()) {
        cout << ans;
        return;
    }

    for (int i = 0; i < n - 2; ++i) {
        if (s[i] == s[i + 2] && (ans.empty() || ans > s.substr(i, 3))) {
            ans = s.substr(i, 3);
        }
    }
    if (!ans.empty()) {
        cout << ans;
        return;
    }

    cout << -1;
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
