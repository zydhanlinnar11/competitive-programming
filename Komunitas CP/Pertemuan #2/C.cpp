#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll q, k, total = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q>>k;
    unordered_map<string, ll> um;
    while(q--) {
        string s;
        ll tmp;
        cin>>s>>tmp;
        if(um.count(s) > 0) {
            um[s] += tmp;
            continue;
        }
        um.insert(make_pair(s, tmp));
    }
    multiset<ll, greater<ll>> ms;
    for(auto i=um.begin(); i != um.end(); i++)
        ms.insert(i->second);
    ll j=0;
    for(auto i=ms.begin(); i != ms.end() && j < k; i++, j++)
        total += *i;
    cout<<total<<'\n';
    return 0;
}