/*
 * https://www.e-olymp.com/en/problems/564
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)

#define MAX 32770
#define ROOT_MAX 182

ll squares[ROOT_MAX];
bool isSquare[MAX];
ll reps[MAX];
ll n;

void initSquares() {
    ll i = 0;
    ll square = 0;
    while (square < MAX) {
        squares[i++] = square;
        isSquare[square] = true;
        square = i * i;
    }
//    FOR(i, 0, ROOT_MAX) {
//        cerr << squares[i] << " " << isSquare[squares[i]] << endl;
//    }
//    cerr << endl;
}

bool done(int diff, int last) {
    if (diff < last) {
        return true;
    }
    if (isSquare[diff]) {
        reps[n]++;
//        cerr << "diff = " << sqrt(diff) << "^2" << endl;
    }
    return false;
}

void solve() {
//    cerr << "n = " << n << endl;
    if (reps[n] < 1) {
        // One
        if (isSquare[n]) {
            reps[n]++;
//            cerr << sqrt(n) << "^2" << endl;
        }
        // Two
        FOR(i, 1, ROOT_MAX) {
            if (done(n - squares[i], squares[i])) {
                break;
            }
        }
        // Three
        FOR(i, 1, ROOT_MAX) {
            FOR(j, i, ROOT_MAX) {
                if (done(n - squares[i] - squares[j], squares[j])) {
                    break;
                }
            }
        }
        // Four
        FOR(i, 1, ROOT_MAX) {
            FOR (j, i, ROOT_MAX) {
                FOR(k, j, ROOT_MAX) {
                    if (done(n - squares[i] - squares[j] - squares[k], squares[k])) {
                        break;
                    }
                }
            }
        }
    }
    cout << reps[n] << endl;
//    cerr << endl;
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("error.txt", "w", stderr);

    initSquares();
    int tc;
    cin >> tc;
    FOR(i, 0, tc) {
        cin >> n;
        solve();
    }

    return 0;
}
