#include <bits/stdc++.h>
using namespace std;
int *par, *_rank;

int find(int x) {
    if(par[x] != x)
        return par[x] = find(par[x]);
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    par = new int[n];
    _rank = new int[n];
    for(int i=0; i<n; i++)
        par[i] = i, _rank[i] = 1;
    for(int i=0; i<m; i++) {
        int u, v, paru, parv;
        cin>>u>>v;
        u--, v--;
        paru = find(u), parv = find(v);
        if(paru != parv) {
            if(_rank[paru] > _rank[parv])
                _rank[paru] += _rank[parv], par[parv] = par[paru];
            else _rank[parv] += _rank[paru], par[paru] = par[parv];
        } else {
            cout<<i + 1<<'\n';
            exit(0);
        }
    }
    cout<<"-1\n";
    return 0;
}