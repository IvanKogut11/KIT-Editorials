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
    getline(cin, s);
    int n = s.size();
    vector<char> opening_brackets = {'{', '[', '('};
    vector<char> closing_brackets = {'}', ']', ')'};

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            cout << opening_brackets[min(2, cnt)];
            ++cnt;
        } else if (s[i] == ')') {
            --cnt;
            cout << closing_brackets[min(2, cnt)];
        } else {
            cout << s[i];
        }
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
