#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

bool comp(ppiii a, ppiii b) {
    if(a.first.first == b.first.first)
        return a.first.second > b.first.second;
    else return a.first.first > b.first.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n;
    unordered_map<int, int> um;
    while(n--) {
        int tmp;
        cin>>tmp;
        auto it = um.find(tmp);
        if(it == um.end())
            um.insert(make_pair(tmp, 1));
        else it->second++;
    }
    cin>>m;
    vector<ppiii> cinemas(m, make_pair(make_pair(0, 0), 0));
    for(int i=0; i<m; i++) {
        int a;
        cin>>a;
        auto it = um.find(a);
        int very = ((it != um.end()) ? it->second : 0);
        cinemas[i].first.first = very;
        cinemas[i].second = i + 1;
    }
    for(int i=0; i<m; i++) {
        int a;
        cin>>a;
        auto it = um.find(a);
        int almost = ((it != um.end()) ? it->second : 0);
        cinemas[i].first.second = almost;
    }
    sort(cinemas.begin(), cinemas.end(), comp);
    cout<<cinemas[0].second<<'\n';
    return 0;
}