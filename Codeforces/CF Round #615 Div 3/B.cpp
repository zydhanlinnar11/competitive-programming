#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void prog() {
    int n;
    cin>>n;
    vector<pii> vpi;
    for(int i=0; i<n; i++) {
        pii tmp;
        cin>>tmp.first>>tmp.second;
        vpi.push_back(tmp);
    }
    sort(vpi.begin(), vpi.end());
    string ans;
    pii curr = make_pair(0, 0);
    for(int i=0; i<n; i++) {
        pii delta;
        delta.first = vpi[i].first - curr.first;
        delta.second = vpi[i].second - curr.second;
        if (delta.first < 0 || delta.second < 0) {
            cout<<"NO\n";
            return;
        }
        for(int j=0; j < delta.first; j++)
            ans.push_back('R');
        for(int j=0; j < delta.second; j++)
            ans.push_back('U');
        curr = vpi[i];
    }
    cout<<"YES\n"<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) prog();
}