/*
 * https://www.e-olymp.com/en/problems/987
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
//#define FORE(i, a, b) \
//    for (int i = (a); i <= (b); i++)
//#define FORD(i, a, b) \
//    for (int i = (a); i >= (b); i--)

#define MAX 101

ll arr[MAX];
ll dp[MAX];
ll n;

void input() {
    cin >> n;
    FOR(i, 0, n) {
        cin >> arr[i];
    }
}

void solve() {
    if (n < 2) {
        cout << 0;
    } else {
        sort(arr, arr + n);
//        FOR(i, 0, n) {
//            cerr << arr[i] << endl;
//        }
//        cerr << endl;
        dp[1] = arr[1] - arr[0];
        if (n > 2) {
            dp[2] = arr[2] - arr[1] + dp[1];
        }
        if (n > 3) {
            dp[3] = arr[3] - arr[2] + dp[1];
        }
        if (n > 4) {
            FOR(i, 4, n) {
                dp[i] = arr[i] - arr[i - 1] + min(dp[i - 1], dp[i - 2]);
            }
        }
        cout << dp[n - 1];
    }
    cout << endl;
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("error.txt", "w", stderr);
    input();
    solve();

    return 0;
}
