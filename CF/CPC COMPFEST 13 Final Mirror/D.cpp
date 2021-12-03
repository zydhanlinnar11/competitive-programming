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

int ans = 0;
vector<int> udah;

inline void solve(string &s, int depth, int x = -1, int res = 0) {
    if(depth == (int)s.length()) {
        int dbg = res % 25 == 0 && ((int)s.length() == 1 || s[0] != '0');
        ans += dbg;
        // if(dbg) cout<<res<<'\n';
        return;
    }
    if(s[depth] == 'X') {
        if(x == -1) {
            for(int i=(depth == 0 && (int)s.length() > 1); i<=9; i++) {
                s[depth] = i + '0';
                solve(s, depth + 1, i, res * 10 + i);
            }
        } else {
            s[depth] = x + '0';
            solve(s, depth + 1, x, res * 10 + x);
        }
        s[depth] = 'X';
        return;
    } else if(s[depth] == '_') {
        for(int i=(depth == 0 && (int)s.length() > 1); i<=9; i++) {
            s[depth] = i + '0';
            solve(s, depth + 1, x, res * 10 + i);
        }
        s[depth] = '_';
        return;
    }
    solve(s, depth + 1, x, res * 10 + s[depth] - '0');
}

void prog() {
    string s;
    cin>>s;
    solve(s, 0);
    cout<<ans<<'\n';
}

int main() {
    // chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--) prog();
    // chrono_time_end = system_clock::now();
    // duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}