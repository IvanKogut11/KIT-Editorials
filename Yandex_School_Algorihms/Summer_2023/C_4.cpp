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
    int k;
    cin >> k;
    string s;
    cin >> s;

    vector<int> as_first_char_pos;
    for (int i = 1; i < k; ++i) {
        if (s[i] > s[0]) {
            cout << "Yes\n";
            return;
        }
        if (s[i] == s[0]) {
            as_first_char_pos.push_back(i);
        }
    }

    for (int pos : as_first_char_pos) {
        if (s.substr(0, pos) < s.substr(pos)) {
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
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
    multitest();
    //solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}
