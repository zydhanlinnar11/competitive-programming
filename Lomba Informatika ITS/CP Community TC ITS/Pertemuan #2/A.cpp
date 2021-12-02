#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, total = 0;
    unordered_multiset<ll> ms;
    unordered_map<ll, bool> um;
    cin>>n;
    while(n--) {
        ll tmp;
        cin>>tmp;
        ms.insert(tmp);
    }
    for(auto i=ms.begin(); i != ms.end(); i++) {
        if(um[*i])
            continue;
        ll count = ms.count(*i);
        if(*i > count)
            total += count;
        else if(count > *i)
            total += (count - *i);
        um[*i] = true;
    }
    cout<<total<<'\n';
    return 0;
}