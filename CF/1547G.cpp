#include <bits/stdc++.h>
#define mp(x, y) make_pair(x, y)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void dfs1(int u, vector<int> adjList[], vector<int> &color, vector<int> &inf, vector<int> &two) {
    color[u] = 1;
    for(int &i: adjList[u]) {
        if(color[i] == 0) dfs1(i, adjList, color, inf, two);
        else if(color[i] == 1) inf.push_back(i);
        else two.push_back(i);
    }
    color[u] = 2;
}

void dfs2(int u, vector<int> adjList[], vector<int> &color) {
    color[u] = 1;
    for(int &i: adjList[u]) {
        if(color[i] == 0) dfs2(i, adjList, color);
    }
    color[u] = 2;
}

void prog() {
    int n, m;
    cin>>n>>m;
    vector<int> adjList[n];
    vector<int> colors(n), inf, two;
    vector<vector<int>> groups(2, vector<int>(n, 0));
    for(int i=0; i<m; i++) {
        int a, b;
        cin>>a>>b;
        a--, b--;
        adjList[a].push_back(b);
    }
    dfs1(0, adjList, colors, inf, two);
    for(auto &node: inf)
        dfs2(node, adjList, groups[0]);
    for(auto &node: two)
        dfs2(node, adjList, groups[1]);
    for(int i=0; i<n; i++) {
        if(colors[i] == 0) {
            cout<<0<<" \n"[i == n - 1];
            continue;            
        }
        if(groups[0][i] != 0) {
            cout<<-1<<" \n"[i == n - 1];
            continue;
        }
        if(groups[1][i] != 0) {
            cout<<2<<" \n"[i == n - 1];
            continue;
        }
        cout<<1<<" \n"[i == n - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) prog();
}