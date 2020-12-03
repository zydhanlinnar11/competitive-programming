#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define mpair make_pair

ll dijkstra(vector<pll> adjList[], ll n) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    bool visited[n] = {0};
    ll dist[n] = {0};
    pq.push(mpair(0, 0));
    while(!pq.empty()) {
        pll top = pq.top();
        pq.pop();
        if(visited[top.second])
            continue;
        visited[top.second] = true;
        dist[top.second] = top.first;
        for(int i=0; i<adjList[top.second].size(); i++) {
            if(!visited[adjList[top.second][i].second])
                pq.push(mpair(top.first + adjList[top.second][i].first, adjList[top.second][i].second));
        }
    }
    return dist[n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<pll> adjList[n];
    for(int i=0; i<m; i++) {
        ll u, v, w;
        cin>>u>>v>>w;
        adjList[u - 1].push_back(mpair(w, v - 1));
        adjList[v - 1].push_back(mpair(w, u - 1));
    }
    cout<<dijkstra(adjList, n)<<'\n';
    return 0;
}