#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;


typedef long double ld;

// Definition of constants from statement
const int MAX_METRE = (int)42195;
const int MAX_USER_NUMBER = (int)1e5;

int fenwick_tree[MAX_METRE + 1];

// Fenwick tree add operation
void add(int index, int x) {
    for (; index <= MAX_METRE; index = (index | (index + 1))) {
        fenwick_tree[index] += x;
    }
}

// Fenwick tree get prefix sum operation
int get_prefix_sum(int r) {
    int result = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        result += fenwick_tree[r];
    }

    return result;
}


void solve() {
    int Q;
    cin >> Q;

    // To save user's current page to use then in operations
    vector<int> current_user_page(MAX_USER_NUMBER + 1, -1);

    int all_users_cnt = 0;

    for (int i = 0; i < Q; ++i) {
        string s;
        cin >> s;
        if (s == "RUN") {
            // RUN operation

            int user, page;
            cin >> user >> page;
            if (current_user_page[user] != -1) {
                add(current_user_page[user], -1);
            } else {
                ++all_users_cnt;
            }

            current_user_page[user] = page;
            add(current_user_page[user], 1);
        } else {
            // CHEER operation
            int user;
            cin >> user;

            if (current_user_page[user] == -1) {
                cout << 0 << "\n";
                continue;
            }

            if (all_users_cnt == 1) {
                cout << 1 << "\n";
                continue;
            }

            int users_before_cnt = get_prefix_sum(current_user_page[user] - 1);
            cout << (ld)users_before_cnt / ((ld)all_users_cnt - 1.) << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(6);
    solve();
    return 0;
}


