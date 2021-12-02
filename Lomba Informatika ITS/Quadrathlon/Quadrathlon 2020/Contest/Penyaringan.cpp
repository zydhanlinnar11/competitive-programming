#include <bits/stdc++.h>
using namespace std;
#define make_pair mpair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
#define MOD 1000000007

ll modadd(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ll a[n], b[n]; 
    a[0] = b[0] = 1; 
    for (int i = 1; i < n; i++) { 
        a[i] = modadd(a[i-1], b[i-1]); 
        b[i] = a[i-1] % MOD; 
    } 
    cout<<modadd(a[n-1], b[n-1])<<'\n'; 
    return 0;
}