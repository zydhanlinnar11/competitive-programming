#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin>>n>>m>>q;
    vector<int> tumpukan[m];
    for(int i=0; i<m; i++) {
        int l, tmp;
        cin>>l;
        for(int j=0; j<l; j++) {
            cin>>tmp;
            tumpukan[i].push_back(tmp);
        }
    }
    for(int i=0; i<q; i++) {
        
        int cmd;
        cin>>cmd;
        if(cmd == 1) {
            int p, t;
            cin>>p>>t;
            tumpukan[t - 1].push_back(p);
        } else if(cmd == 2) {
            int t;
            cin>>t;
            tumpukan[t - 1].pop_back();
        } else {
            int t1, t2;
            cin>>t1>>t2;
            tumpukan[t2 - 1].insert( tumpukan[t2 - 1].end(), tumpukan[t1 - 1].begin(), tumpukan[t1 - 1].end() );
            tumpukan[t1 -1].clear();
        }
        
    }
    for(int i=0; i<m; i++) {
        if(!tumpukan[i].empty()) {
            cout<<i + 1<<": ";
            int sizequeue = tumpukan[i].size();
            for(auto j=0; j<sizequeue; j++) {
                cout<<tumpukan[i][j]<<((j == (sizequeue - 1)) ? '\n' : ' ');
                // tumpukan[i].pop_front();
            }
        }
    }
}