/*
 * https://www.e-olymp.com/en/problems/668
 * Category: Graph
 * Solution: Dijkstra
 */

#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> ipii;
#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define MAX_V 1002

int noVertices, maxTickets, source, target, noBuses, noPlanes;
list<pii> busLines[MAX_V];
list<pii> planeFlights[MAX_V];
int dist[MAX_V][12]; // dist[u][t] == min path from source to u with t plane tickets bought

int dijkstra() {
    priority_queue<ipii, vector<ipii>, greater<ipii> > minHeap;
    FORE(i, 1, noVertices) {
        FORE(j, 0, maxTickets) {
            dist[i][j] = INT_MAX;
        }
    }
    FORE(j, 0, maxTickets) {
        dist[source][j] = 0;
    }
    minHeap.push(make_pair(0, make_pair(source, 0)));
    while (!minHeap.empty()) {
        int u = minHeap.top().second.first;
        int boughtTickets = minHeap.top().second.second;
        if (u == target) {
            return dist[u][boughtTickets];
        }
        minHeap.pop();
        for (auto &busLine : busLines[u]) {
            int v = busLine.first;
            int weight = busLine.second;
            if (dist[v][boughtTickets] > dist[u][boughtTickets] + weight) {
                dist[v][boughtTickets] = dist[u][boughtTickets] + weight;
                minHeap.push(make_pair(dist[v][boughtTickets], make_pair(v, boughtTickets)));
            }
        }
        if (boughtTickets < maxTickets) {
            for (auto &planeFlight : planeFlights[u]) {
                int v = planeFlight.first;
                int weight = planeFlight.second;
                if (dist[v][boughtTickets + 1] > dist[u][boughtTickets] + weight) {
                    dist[v][boughtTickets + 1] = dist[u][boughtTickets] + weight;
                    minHeap.push(make_pair(dist[v][boughtTickets + 1], make_pair(v, boughtTickets + 1)));
                }
            }
        }
    }
    return 0;
}

void input() {
    cin >> noVertices >> maxTickets >> source >> target;
    cin >> noBuses;
    int u, v, weight;
    FOR(i, 0, noBuses) {
        cin >> u >> v >> weight;
        busLines[u].emplace_back(make_pair(v, weight));
        busLines[v].emplace_back(make_pair(u, weight));
    }
    cin >> noPlanes;
    FOR(i, 0, noPlanes) {
        cin >> u >> v >> weight;
        planeFlights[u].emplace_back(make_pair(v, weight));
        planeFlights[v].emplace_back(make_pair(u, weight));
    }
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("error.txt", "w", stderr);
    input();
    cout << dijkstra() << endl;
    return 0;
}
