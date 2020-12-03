#include <bits/stdc++.h>
using namespace std;
vector<int> *adjList;
vector<short> state;

bool dfs(int dst) {
    if(state[dst] == 1)
        return false;
    if(state[dst] == 2)
        return true;
    state[dst] = 1;
    bool ret = true;
    for(int i=0; i < adjList[dst].size() && ret; i++)
        ret &= dfs(adjList[dst][i]);
    state[dst] = 2;
    return ret;
}

bool topsort(int n) {
    for(int i=0; i<n; i++) {
        if(state[i] != 2 && !dfs(i))
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    adjList = new vector<int>[n];
    state.resize(n);
    for(int i=0; i<n; i++)
        state[i] = 0;
    for(int i=0; i<m; i++) {
        int src, dst;
        cin>>src>>dst;
        src--, dst--;
        adjList[src].push_back(dst);
    }
    cout<<(topsort(n) ? "aman" : "konflik")<<'\n';
    return 0;
}