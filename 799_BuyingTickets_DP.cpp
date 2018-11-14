/*
 * https://www.e-olymp.com/en/problems/799
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

#define MAX 5001

// cost[i][0] is cost for only the ith person
// cost[i][1] is cost for the ith and (i+1)th people
// cost[i][2] is cost for the ith, (i+1)th and (i+2)th people
ll cost[MAX][3];
// dp[i] is min total cost people from 0 to i
ll dp[MAX];
ll n;

void input() {
    cin >> n;
    FOR(i, 0, n) {
        FOR(j, 0, 3) {
            cin >> cost[i][j];
        }
    }
}

void solve() {
//    cerr << cost[0][0] << endl;
    // min total cost for only the first person is cost[0][0]
    dp[0] = cost[0][0];
    if (n > 1) {
        // min total cost for the first 2 people is
        //      min(dp[0] + cost[1][0], cost[0][1])
//        cerr << dp[0] + cost[1][0] << "\t"
//             << cost[1][1] << endl;
        dp[1] = min(dp[0] + cost[1][0], cost[0][1]);
    }
    if (n > 2) {
//        cerr << dp[1] + cost[2][0] << "\t"
//             << dp[0] + cost[1][1] << "\t"
//             << cost[0][2] << endl;
        dp[2] = min(
                min(dp[1] + cost[2][0],
                    dp[0] + cost[1][1]),
                cost[0][2]);
    }
    if (n > 3) {
        FOR(i, 3, n) {
//            cerr << dp[i - 1] + cost[i][0] << "\t"
//                 << dp[i - 2] + cost[i - 1][1] << "\t"
//                 << dp[i - 3] + cost[i - 2][2] << endl;
            dp[i] = min(
                    min(dp[i - 1] + cost[i][0],
                        dp[i - 2] + cost[i - 1][1]),
                    dp[i - 3] + cost[i - 2][2]);
        }
    }
//    cerr << endl;
//    FOR(i, 0, n) {
//        cerr << dp[i] << endl;
//    }
    cout << dp[n - 1];
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
