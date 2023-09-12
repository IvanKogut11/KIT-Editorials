#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const int INT_INF = (int)1e9 + 300;
const ll LL_INF = (ll)1e18 + (ll)300;

const int MAX_N = (int)1e6 + 10;

vector<ll> right_numbers;

void solve() {
    ll x;
    cin >> x;
    int l = -1, r = right_numbers.size();
    while (r - l != 1) {
        int mid = (l + r) / 2;
        if (right_numbers[mid] <= x) {
            l = mid;
        } else {
            r = mid;
        }
    }

    if (l == -1) {
        cout << -1 << "\n";
    } else {
        cout << right_numbers[l] << "\n";
    }
}

void multitest() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

void precalc() {
    for (int bit_1 = 2; bit_1 <= 62; ++bit_1) {
        for (int bit_2 = 1; bit_2 < bit_1; ++bit_2) {
            for (int bit_3 = 0; bit_3 < bit_2; ++bit_3) {
                right_numbers.push_back((1LL << bit_1) | (1LL << bit_2) | (1LL << bit_3));
            }
        }
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
    precalc();
    multitest();
    //solve();
#ifdef LOCAL
    printf("\n\n%.3f s", (double)clock() / CLOCKS_PER_SEC);
#endif
    return 0;
}
