#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

int main() {
    int n;
    cin>>n;
    vector<pair<string, ll>> resto(n);
    for(auto &[s, p]: resto)
        cin>>s>>p;
    vector<vector<pll>> adjList(n+1);
    int m; cin>>m;
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    priority_queue<pll> q;
    vl dist(n+1, INT64_MAX);
    q.push({0, 0});
    dist[0] = 0;
    while(!q.empty()) {
        auto [l, u] = q.top();
        q.pop();
        l = -l;
        for(auto &[v, d]: adjList[u]) {
            if(dist[v] <= l + d)
                continue;
            dist[v] = l + d;
            q.push({-l - d, v});
        }
    }
    int mx; cin>>mx;
    int ans = 0;
    for(int i=1; i<=n; i++) {
        if(dist[i] > mx) continue;
        if(ans == 0 || resto[ans - 1].second > resto[i - 1].second)
            ans = i;
    }
    cout<<"hari ini makan di "<<resto[ans-1].first<<"\n";
}