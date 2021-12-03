#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mp(x, y) make_pair(x, y)
#define FORINC(i, a, n) for(int i=a; i<n; i++)
#define FORDEC(i, a, n) for(int i=n - 1; i>=a; i--)
using namespace std;
using namespace chrono;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vi> vi2d;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

ll modmul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll modpow (ll a, ll b) {
    a %= MOD;
    if(b == 1) return a;
    if(b == 0) return 1;
    if(b & 1) {
        return modmul(modpow(a, b - 1), a);
    } else {
        ll res = modpow(a, b >> 1);
        return modmul(res, res);
    }
}

ll comb(ll n, ll k, vi &factorial) {
    ll nk = n - k;
    k = modpow(factorial[k], MOD - 2);
    nk = modpow(factorial[nk], MOD - 2);
    return modmul(modmul(factorial[n], k), nk);
}

void scanArray(vi &arr, int n) {
    FORINC(i, 0, n)
        cin>>arr[i];
}

int countPrimeDivisors(int a) {
    int ans = 0;
    for(int i=2; i*i<=a; i++) {
        while(a % i == 0) {
            ans++;
            a /= i;
        }
    }
    if(a > 1) ans++;
    return ans;
}

void prog() {
    int a, b, k;
    cin>>a>>b>>k;
    int m = 2, gcd = __gcd(a, b), n = countPrimeDivisors(a) + countPrimeDivisors(b);
    if(a == b) m = 0;
    else if(gcd == a || gcd == b) m = 1;
    if((m <= k && k <= n) && ((k == 1 && m == 1) || (k != 1))) cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
    // chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--) prog();
    // chrono_time_end = system_clock::now();
    // duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}