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
    if(n == 2) {
        ll a, b;
        cin>>a>>b;
        cout<<a+b<<'\n';
        return 0;
    }
    ll total = 0;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    sort(arr, arr + n);
    // int before = 0;
    for(int i=0; i<n; i++) {
        int it = arr[i];
        int next = i + (n - 1);
        if(arr[i] == 0)
            break;
        total++;
        for(int j=i+1; j<i + (n - 1) && j < n; j++) {
            arr[j] -= it;
            if(arr[j] > 0)
                next = min(j, next);
        }
        i = next - 1;
    }
    cout<<total<<'\n';
    return 0;
}