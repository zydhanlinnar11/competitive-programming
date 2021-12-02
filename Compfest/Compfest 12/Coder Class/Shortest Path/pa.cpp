#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plpll;
typedef pair<int, int> pii;
#define mpair make_pair
vector<int> *before;

void dijkstramod(vector<pll> adjList[], int &n) {
    for(int i=0; i<n; i++) {
        before[i][i] = -1;
        vector<ll> dist(n, INT64_MAX);
        bool visited[n] = {0};
        priority_queue<plpll, vector<plpll>, greater<plpll>> pq;
        pq.push(mpair(0, mpair(i, i)));
        while(!pq.empty()) {
            plpll top = pq.top();
            pq.pop();
            if(visited[top.second.first])
                continue;
            visited[top.second.first] = true;
            dist[top.second.first] = top.first;
            before[i][top.second.first] = top.second.second;
            for(int j=0; j < adjList[top.second.first].size(); j++) {
                if(!visited[adjList[top.second.first][j].second]) {
                    pq.push(mpair(adjList[top.second.first][j].first + top.first, mpair(adjList[top.second.first][j].second, top.second.first)));
                }
            }
        }
    }
}

void print(int src, int dst, bool first) {
    if(src != dst)
        print(src, before[src][dst], false);
    cout<<dst + 1<<(first ? '\n' : ' ');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin>>n>>m>>q;
    vector<pll> adjList[n];
    before = new vector<int>[n];
    for(int i=0; i<n; i++)
        before[i].resize(n);
    for(int i=0; i<m; i++) {
        ll u, v, w;
        cin>>u>>v>>w;
        adjList[u - 1].push_back(mpair(w, v - 1));
        adjList[v - 1].push_back(mpair(w, u - 1));
    }
    dijkstramod(adjList, n);
    // for(int i=0; i<n; i++) {
    //     for(int j : before[i])
    //         cout<<j<<' ';
    //     cout<<'\n';
    // }
    for(int i=0; i<q; i++) {
        int src, dst;
        cin>>src>>dst;
        src--, dst--;
        print(src, dst, true);
    }
    return 0;
}