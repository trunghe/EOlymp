/*
 * https://www.e-olymp.com/en/problems/838
 */
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
//#define FORE(i, a, b) \
//    for (int i = (a); i <= (b); i++)
//#define FORD(i, a, b) \
//    for (int i = (a); i >= (b); i--)

#define MAX 256
int n;
int dp[MAX][MAX];
ii previous[MAX][MAX];

void update(int i1, int j1, int i2, int j2) {
    dp[i1][j1] += dp[i2][j2];
    previous[i1][j1] = make_pair(i2, j2);
}

void input() {
    char ch;
    int i2, j2;
    cin >> n;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            i2 = i;
            j2 = j;
            cin >> ch;
            dp[i][j] = ch - '0';
            if (i > 0) {
                if (j > 0) {
                    if (dp[i][j - 1] < dp[i - 1][j]) {
                        j2 = j - 1;
                    } else {
                        i2 = i - 1;
                    }
                } else {
                    i2 = i - 1;
                }
                update(i, j, i2, j2);
            } else {
                if (j > 0) {
                    j2 = j - 1;
                    update(i, j, i2, j2);
                } else {
                    previous[i][j] = make_pair(-1, -1); // Starting point
                }
            }
        }
    }

    // DEBUG
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cerr << dp[i][j] << "\t";
        }
        cerr << endl;
    }
    cerr << endl;
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cerr    << "("
                    << previous[i][j].first
                    << ","
                 << previous[i][j].second << ")\t";
        }
        cerr << endl;
    }
}


void solve() {
    char results[n][n];
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            results[i][j] = '.';
        }
    }
    int i = n - 1, j = n - 1;
    while (i > -1) {
        results[i][j] = '#';
        int i2 = previous[i][j].first;
        int j2 = previous[i][j].second;
        i = i2, j = j2;
    }
//    cout << dp[n - 1][n - 1] << endl << endl;
    FOR(row, 0, n) {
        FOR(col, 0, n) {
            cout << results[row][col];
        }
        cout << endl;
    }
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
