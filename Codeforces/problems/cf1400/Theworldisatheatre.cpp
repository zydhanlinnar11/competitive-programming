#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

ll combination(ll n, ll r) {
    ll newr = max(n - r, r);
    ll res = 1;
    queue<ll> q;
    for(ll i = 2; i <= n - newr; i++)
        q.push(i);
    for(ll i=newr + 1; i<=n; i++) {
        res *= i;
        while(!q.empty() && res % q.front() == 0) {
            res /= q.front();
            q.pop();
        }
    }

    // while (!q.empty()) {
    //     res /= q.front();
    //     q.pop();
    // }
    
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n_boys, n_girls, actors;
    cin>>n_boys>>n_girls>>actors;

    unsigned long long res = 0;
    for(ll i=4; i<=n_boys; i++) {
        if(actors - i < 1) break;
        if(actors - i > n_girls) continue;
        res += combination(n_boys, i) * combination(n_girls, actors - i);
    }

    cout<<res<<'\n';

    return 0;
}