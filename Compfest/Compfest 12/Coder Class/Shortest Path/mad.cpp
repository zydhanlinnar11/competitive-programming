#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define mpair make_pair

string bellmanford(vector<pair<ll, pii>> &edgeList, int &n, int &src) {
    vector<ll> dist(n, INT64_MAX);
    dist[src] = 0;
    int n_edge = edgeList.size();
    for(int i=0; i<(n - 1); i++) {
        for(int j=0; j < n_edge; j++) {
            if(dist[edgeList[j].second.first] != INT64_MAX &&
            dist[edgeList[j].second.first] + edgeList[j].first < dist[edgeList[j].second.second])
                dist[edgeList[j].second.second] = dist[edgeList[j].second.first] + edgeList[j].first;
        }
    }
    for(int j=0; j < n_edge; j++) {
        if(dist[edgeList[j].second.first] != INT64_MAX &&
        dist[edgeList[j].second.first] + edgeList[j].first < dist[edgeList[j].second.second])
            return "TIDAK\n";
    }
    return "BISA\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, src, dst;
    cin>>src>>dst;
    src--, dst--;
    cin>>n>>m;
    vector<pair<ll, pii>> edgeList;
    for(int i=0; i<m; i++) {
        int u, v;
        ll w;
        cin>>u>>v>>w;
        edgeList.push_back(mpair(w, mpair(u - 1, v - 1)));
    }
    cout<<bellmanford(edgeList, n, src);
    return 0;
}