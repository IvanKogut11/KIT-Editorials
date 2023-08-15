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

    int first_miss = -1;
    bool f = false;
    for (int l = (n - 1) / 2, r = n / 2; l >= 0 && r < n; --l, ++r) {
        if (s[l] == s[r]) {
            continue;
        }

        if (first_miss == -1) {
            first_miss = l;
            continue;
        }

        int l_pos_1 = first_miss, l_pos_2 = l;
        int r_pos_1 = n - 1 - first_miss, r_pos_2 = r;
        if (s[l_pos_1] == s[r_pos_2] && s[l_pos_2] == s[r_pos_1]) {
            swap(s[l_pos_1], s[l_pos_2]);
            f = true;
            break;
        }
        if (s[r_pos_2] == s[r_pos_1] && s[l_pos_1] == s[l_pos_2]) {
            swap(s[r_pos_2], s[l_pos_1]);
            f = true;
            break;
        }
        break;
    }
    if (!f && first_miss != -1) {
        if (s[n / 2] == s[first_miss]) {
            swap(s[n / 2], s[n - first_miss - 1]);
        } else if (s[n / 2] == s[n - first_miss - 1]) {
            swap(s[n / 2], s[first_miss]);
        }
    }

    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1]) {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
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
