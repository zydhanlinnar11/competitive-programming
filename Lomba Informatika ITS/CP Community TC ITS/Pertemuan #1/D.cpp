#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

int main() {
    ll n, t, d, curr = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(ll i=0; i<n; i++) {
        cin>>t>>d;
        if(t > curr)
            curr = t + d;
        else
            curr += d;
    }
    cout<<curr<<endl;
}