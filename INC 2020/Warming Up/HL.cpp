#include <bits/stdc++.h>
using namespace std;
bool *visited;
map<pair<int, int>, bool> calculated;
map<pair<int, int>, int> n_paths;
vector<int> path;
vector<int> *adjList;
void dfs(int now, int dst) {
    for(int i : path) {
        pair<int, int> srcdst = make_pair(min(now, i), max(now, i));
        if(calculated[srcdst])
            n_paths[srcdst]++;
        else {
            calculated[srcdst] = true;
            n_paths[srcdst] = 1;
        }
    }
    if(now == dst) {
        path.clear();
        return;
    }
    path.push_back(now);
    for(int i : adjList[now])
        dfs(i, dst);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin>>n>>m>>q;
    visited = new bool[n];
    adjList = new vector<int>[n];
    for(int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        adjList[u - 1].push_back(v - 1);
        adjList[v - 1].push_back(u - 1);
    }
}