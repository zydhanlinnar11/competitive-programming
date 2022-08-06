#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mp(x, y) make_pair(x, y)
using namespace std;
using namespace chrono;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

#define MXX 40000

vi palindromics;
vvl dp;

bool isPalindrome(string s) {
    int n = s.length();
    for(int i=0; i<n; i++) {
        if(s[i] != s[n - i - 1])
            return false;
    }
    return true;
}

ll compute(int type, int n) {
    if(n == 0) return 1;
    if((type == (int)palindromics.size()) || (n < 0))
        return 0;
    auto &ans = dp[type][n];
    if(ans != -1) return ans;
    return (ans = ((compute(type + 1, n) + compute(type, n - palindromics[type])) % MOD));
}

inline void prog() {
    int n;
    cin>>n;
    cout<<compute(0, n)<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/CF/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/CF/out", "w", stdout);
    #endif
    for(int i=1; i<=MXX; i++) {
        if(isPalindrome(to_string(i)))
            palindromics.push_back(i);
    }
    dp = vvl(palindromics.size(), vl(MXX+1, -1));
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}