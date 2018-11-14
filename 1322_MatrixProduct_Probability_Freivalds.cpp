/*
 * https://www.e-olymp.com/en/problems/1322
 */
#include <bits/stdc++.h>

using namespace std;

#define MAX 512
#define MIN_TRIES 10

int a[MAX][MAX];
int b[MAX][MAX];
int c[MAX][MAX];
int N;

bool solve() {
// Function to check if ABx = Cx
    // Generate a random vector
    bool r[N];
    for (int i = 0; i < N; i++)
        r[i] = rand() % 2;

    // Now comput B*r for evaluating
    // expression A * (B*r) - (C*r)
    int br[N];
    memset(br, 0, sizeof(int) * N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            br[i] = br[i] + b[i][j] * r[j];

    // Now comput C*r for evaluating
    // expression A * (B*r) - (C*r)
    int cr[N];
    memset(cr, 0, sizeof(int) * N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cr[i] = cr[i] + c[i][j] * r[j];

    // Now comput A* (B*r) for evaluating
    // expression A * (B*r) - (C*r)
    int axbr[N];
    memset(axbr, 0, sizeof(int) * N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            axbr[i] = axbr[i] + a[i][j] * br[j];

    // Finally check if value of expression
    // A * (B*r) - (C*r) is 0 or not
    for (int i = 0; i < N; i++)
        if (axbr[i] - cr[i] != 0)
            return false;

    return true;
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("error.txt", "w", stderr);

    while (scanf("%d", &N) == 1 && N) {
        //input ma trận A
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        //input ma trận B
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &b[i][j]);
            }
        }
        //input ma trân C
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &c[i][j]);
            }
        }
        bool flag = true;
        for (int i = 0; i < MIN_TRIES; i++) {
            if (!solve()) {
                flag = false;
                break;
            }
        }
        printf((flag ? "YES\n" : "NO\n"));
    }
    return 0;
}
