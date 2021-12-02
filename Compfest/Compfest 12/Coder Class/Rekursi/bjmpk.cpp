#include <bits/stdc++.h>
using namespace std;
unsigned long long jalur = 0ULL;

void dfs(short &n, short&m, short posy, short posx) {
    if(posy > n || posx > m)
        return;
    if(posy == n && posx == m) {
        jalur++;
        return;
    }
    dfs(n, m, posy + 1, posx);
    dfs(n, m, posy, posx + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    short n, m;
    cin>>n>>m;
    dfs(n, m, 1, 1);
    cout<<jalur<<'\n';
    return 0;
}