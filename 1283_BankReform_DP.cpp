/*
 * https://www.e-olymp.com/en/problems/1283
 * Category: Dynamic Programming
 * Vu Thanh Trung 2018/11/02
 */

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MAX 1500

static ll c[5] = {0, 1, 2, 5, 10};
static ll dp[MAX][5];

void init() {
    for (int j = 0; j < 5; ++j) {
        dp[0][j] = 1;
    }
    for (int i = 0; i < MAX; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j < 5; ++j) {
            if (i < c[j]) {
                dp[i][j] = dp[i][j - 1];
            } else {
                dp[i][j] = dp[i - c[j]][j] + dp[i][j - 1];
            }
        }
    }
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

    init();
    int s;
    while (cin >> s) {
        cout << dp[s / 5][4] << endl;
    }

    return 0;
}
