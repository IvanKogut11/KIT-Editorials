#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const int INT_INF = (int)1e9 + 300;
const ll LL_INF = (ll)1e18 + (ll)300;

const int MAX_N = (int)2e5 + 10;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int n;
    cin >> n;
    int x1 = min(4 * a, 2 * b);
    x1 = min(x1, c);
    int x2 = d;
    if (2 * x1 <= d) {
        cout << (ll)x1 * n;
    } else {
        cout << (n / 2) * (ll)x2 + (n % 2) * x1;
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
    cout << fixed << setprecision(6);
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
