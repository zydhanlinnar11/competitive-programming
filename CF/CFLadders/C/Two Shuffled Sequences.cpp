#include <bits/stdc++.h>
using namespace std;
int jmlh[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    bool bisa = true;
    int n;
    cin>>n;
    set<int, less<int>> inc;
    set<int, greater<int>> dec;
    for(int i=0; i<n; i++) {
        int tmp;
        cin>>tmp;
        if(jmlh[tmp] == 0) {
            dec.insert(tmp);
        } else if(jmlh[tmp] == 1) {
            inc.insert(tmp);
        } else bisa = false;
        jmlh[tmp]++;
    }
    if(!bisa)
        cout<<"NO\n";
    else {
        cout<<"YES\n";
        auto i = inc.begin();
        cout<<inc.size()<<'\n';
        if(i != inc.end()) {
            cout<<*i;
            i++;
        }
        for(; i != inc.end(); i++)
            cout<<' '<<*i;
        cout<<'\n';
        i = dec.begin();
        cout<<dec.size()<<'\n';
        if(i != inc.end()) {
            cout<<*i;
            i++;
        }
        for(; i != dec.end(); i++)
            cout<<' '<<*i;
        cout<<'\n';
    }
    return 0;
}