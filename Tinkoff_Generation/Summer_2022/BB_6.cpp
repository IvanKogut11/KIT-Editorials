#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const int INT_INF = (int)1e9 + 300;
const ll LL_INF = (ll)1e18 + (ll)300;
const int MOD = (int)1e9 + 7;

const int MAX_N = (int)1e5 + 10;

int mult(int x, int y) {
    return (ll)x * y % MOD;
}

int bin_pow(int x, ll n) {
    int ans = 1;
    for (; n != 0; n >>= 1) {
        if (n & 1) {
            ans = mult(ans, x);
        }
        x = mult(x, x);
    }

    return ans;
}

int fact[MAX_N], inv_fact[MAX_N];

int get_ank(int n, int k) {
    return mult(fact[n], inv_fact[n - k]);
}

vector<int> g[MAX_N];

int dp[MAX_N];

void dfs(int v, int s, int p=-1) {
    dp[v] = 1;

    int child_cnt = 0, child_dp_mult = 1;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        ++child_cnt;
        dfs(to, s - (p == -1), v);

        child_dp_mult = mult(child_dp_mult, dp[to]);
    }
    if (child_cnt > s - 1) {
        dp[v] = 0;
        return;
    }

    dp[v] = mult(child_dp_mult, get_ank(s - 1, child_cnt));
}

void solve() {
    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    fact[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        fact[i] = mult(fact[i - 1], i);
    }
    inv_fact[MAX_N - 1] = bin_pow(fact[MAX_N - 1], MOD - 2);
    for (int i = MAX_N - 2; i >= 0; --i) {
        inv_fact[i] = mult(inv_fact[i + 1], i + 1);
    }

    dfs(0, s);
    cout << mult(dp[0], s);
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
