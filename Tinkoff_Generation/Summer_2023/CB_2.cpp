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
    if (n == 0) {
        cout << 0;
        return;
    }

    vector<int> ans;
    while (n != 0) {
        int d = n / (-2);
        if (n < 0 && n % 2 != 0) {
            ++d;
        }
        ans.push_back(n - (-2) * d);
        n = d;
    }

    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i];
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
