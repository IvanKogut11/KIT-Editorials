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
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        int h, m;
        scanf("%d:%d", &h, &m);
        t[i] = h * 60 + m;
    }
    t.push_back(23 * 60 + 59);

    double battery = 100;
    for (int i = 1; i < t.size(); ++i) {
        int d = t[i] - t[i - 1];
        if (i % 2 != 0) {
            battery = max(0., battery - (100. * d) / a);
        } else {
            battery = min(100., battery + (100. * d) / b);
        }
    }

    printf("%.5lf", battery);
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
