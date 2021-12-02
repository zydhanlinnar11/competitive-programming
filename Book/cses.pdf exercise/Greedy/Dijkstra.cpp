#include <bits/stdc++.h>
using namespace std;
int* dijkstra(vector<pair<int, int>> adjList[], int src, int v) {
    bool visited[v];
    int * distance = new int[v];
    for(int i=0; i<v; i++)
        distance[i] = INT_MAX;
    memset(visited, 0, v * sizeof(bool));
    set<pair<int, int>> pq;
    pq.insert(make_pair(0, src));
    while(!pq.empty()) {
        pair<int, int> now = *pq.begin();
        pq.erase(now);
        if(visited[now.second])
            continue;
        distance[now.second] = now.first;
        visited[now.second] = true;
        for(int i=0; i<adjList[now.second].size(); i++) {
            if(!visited[adjList[now.second][i].first])
                pq.insert(make_pair(now.first + adjList[now.second][i].second, adjList[now.second][i].first));
        }
    }
    return distance;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v, e;
    cin>>v>>e;
    vector<pair<int, int>> adjList[v];
    for(int i=0; i<e; i++) {
        int src, dst, weight;
        // 1-based indexing I/O
        cin>>src>>dst>>weight;
        adjList[src - 1].push_back(make_pair(dst - 1, weight));
        adjList[dst - 1].push_back(make_pair(src - 1, weight));
    }
    int src;
    cin>>src;
    int * distance = dijkstra(adjList, src - 1, v);
    for(int i=0; i<v; i++)
        cout<<"From "<<src<<" to "<<i + 1<<" is "<<distance[i]<<'\n';
}