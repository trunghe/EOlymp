/**
 * https://www.e-olymp.com/en/problems/3526
 * 3526 Anniversary Party
 * Description: Given a tree with n weighted nodes (n <= 6000).
 *          Find the subset of nodes with maximum sum of weights.
 *          Weight w can be negative (-128 <= w <= 127).
 * Catergory: Tree / DP
 * Solution: Post Order Traversal
 * Issues:
 * Author: Vu Thanh Trung
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX 6001
int n;
int c[MAX];
int cost[MAX];
int gain[MAX];
bool notRoot[MAX];
list<int> childrenLists[MAX];

//const bool TESTING = true;

void input();

void solve();

int findRoot();

void postOrder(int root);

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    input();
    solve();
    return 0;
}

void solve() {
    int root = findRoot();
    postOrder(root);
    cout << max(cost[root], gain[root]) << endl;

//    if (TESTING) {
//        cout << "\n\t";
//        for (int i = 0; i < n; i++) {
//            cout << "\t" << (i + 1);
//        }
//        cout << "\nc\t";
//        for (int i = 0; i < n; i++) {
//            cout << "\t" << c[i];
//        }
//        cout << "\ncost";
//        for (int i = 0; i < n; i++) {
//            cout << "\t" << conest[i];
//        }
//        cout << "\ngain";
//        for (int i = 0; i < n; i++) {
//            cout << "\t" << gain[i];
//        }
//        cout << endl;
//    }
}

void postOrder(int p) {
    gain[p] = c[p] > 0 ? c[p] : 0;
    if (childrenLists[p].empty()) {
        return;
    }
    for (int child : childrenLists[p]) {
        postOrder(child);
        cost[p] += gain[child];
        gain[p] += cost[child];
    }
}

int findRoot() {
    for (int i = 0; i < n; i++) {
        if (!notRoot[i]) {
            return i;
        }
    }
    return -1;
}

void input() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    int child, parent;
    cin >> child >> parent;
    while (child != 0) {
        child--, parent--;
        childrenLists[parent].emplace_back(child);
        notRoot[child] = true;
        cin >> child >> parent;
    }
}

