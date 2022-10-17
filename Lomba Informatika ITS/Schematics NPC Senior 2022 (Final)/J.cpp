#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

int main() {
    int n; cin>>n;
    ll stamina; cin>>stamina;
    vl arr(n);
    for(auto &i: arr) cin>>i;
    arr.push_back(0);
    vl dist(n+1, INT64_MAX);
    priority_queue<pll> q;
    q.push({-arr[0], 0});
    q.push({-arr[1], 1});
    dist[0] = arr[0];
    dist[1] = arr[1];
    while(!q.empty()) {
        auto [l, u] = q.top();
        // cout<<l<<" "<<u<<"\n";
        l = -l;
        q.pop();
        for(int i=1; i<=2; i++) {
            ll v = u + i;
            if(v > n || dist[v] <= l + arr[v])
                continue;
            dist[v] = l + arr[v];
            q.push({-dist[v], v});
        }
    }
    cout<<(dist.back() > stamina ? -1 : dist.back())<<"\n";
}