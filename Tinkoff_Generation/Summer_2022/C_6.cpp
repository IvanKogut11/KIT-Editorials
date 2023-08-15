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
    int n, m, c;
    cin >> n >> m >> c;
    if (c % 2 != 0) {
        cout << "NO";
        return;
    }
    c /= 2;


    if (c < 6) {
        cout << "NO";
        return;
    }
    if (n > 1 && m > 1 && c >= 2 * m + 2 * n - max(n, m) + 1 && c <= 2 * m + 2 * n - 1) {
        cout << "YES";
        return;
    }
    if (n >= 3 && 3 * m + n == c) {
        cout << "YES";
        return;
    }
    if (m >= 3 && 3 * n + m == c) {
        cout << "YES";
        return;
    }
    cout << "NO";
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
