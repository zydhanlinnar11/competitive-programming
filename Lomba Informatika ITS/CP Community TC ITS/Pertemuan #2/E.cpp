#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<pair<ll, ll>,null_type,less<pair<ll, ll>>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
void func() {
    int n;
    cin>>n;
    indexed_set s;
    unordered_map<ll, ll> um;
    for(int i=0; i<n; i++) {
        ll tmp;
        cin>>tmp;
        if(um.count(tmp) > 0)
            um[tmp]++;
        else um.insert(make_pair(tmp, 1));
        s.insert(make_pair(tmp, um[tmp]));
        if(i==0)
            cout<<tmp<<'\n';
        else if(i & 1)
            cout<<((double)(*s.find_by_order(i / 2)).first + (*s.find_by_order((i / 2) + 1)).first)/2<<'\n';
        else
            cout<<(*s.find_by_order(i / 2)).first<<'\n';
    }
}

int main() {
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
        func();
    return 0;
}