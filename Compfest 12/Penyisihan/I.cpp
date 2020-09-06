#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define mpair make_pair
#define umap unordered_map
#define uset unordered_set
#define FOR(i, n) for(int i=0; i<n; i++)
int *par;
bool *visited;
int find(int x) {
    if(par[x] != x)
        return par[x] = find(par[x]);
    return x;
}

void bfs(set<pii> &edge, int &n) {
    vector<int> adjList[n];
    for(auto i:edge) {
        adjList[i.first - 1].push_back(i.second - 1);
        adjList[i.second - 1].push_back(i.first - 1);
    }
    queue<int> q;
    FOR(i, n)
        visited[i] = false;

    q.push(0);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        visited[now] = true;
        for(int i=0; i<adjList[now].size(); i++)
            if(!visited[adjList[now][i]])
                q.push(adjList[now][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n, k, l;
    set<pii> edge;
    cin>>n;
    cin>>k;
    FOR(i, k) {
        int a, b;
        cin>>a>>b;
        edge.insert(mpair(min(a, b), max(a, b)));
    }
    cin>>l;
    FOR(i, l) {
        int a, b;
        cin>>a>>b;
        auto same = edge.find(mpair(min(a, b), max(a, b)));
        if(same != edge.end()) {
            edge.erase(same);
        } else edge.insert(mpair(min(a, b), max(a, b)));
    }
    par = new int[n];
    FOR(i, n)
        par[i] = i;
    visited = new bool[n];
    bool isTree = true;
    for(auto i: edge) {
        int parSrc = find(i.first - 1), parDst = find(i.second - 1);
        if(parSrc == parDst) {
            isTree = false;
            break;
        } else {
            par[parDst] = par[parSrc];
        }
    }
    bfs(edge, n);
    FOR(i, n) {
        if(!visited[i])
            isTree = false;
    }
    cout<<(isTree ? "Pohon\n" : "Bukan pohon\n");
    return 0;
}