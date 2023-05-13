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

vi getDivisors(int n) {
    vi divisors;
    for (int i=1; i<=sqrt(n); i++) {
        if (n%i == 0) {
            if (n/i == i) divisors.push_back(i); 
            else {
                divisors.push_back(i);
                divisors.push_back(n/i);
            }
        }
    }
    return divisors;
}

vi cnt(10000001, 0);
vector<bool> counted(10000001, false);

inline void prog() {
    int n;
    cin>>n;
    vi arr(n);
    ull ans = 0;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        cnt[arr[i]]++;
    }
    for(int i=0; i<n; i++) {
        if (counted[arr[i]]) continue;
        counted[arr[i]] = true;
        vi divisors = getDivisors(arr[i]);
        for(int j=0; j<(int)divisors.size(); j++) {
            int divisor = divisors[j];
            if (divisor == 1) {
                ans += (ull)cnt[arr[i]] * (cnt[arr[i]] - 1) * (cnt[arr[i]] - 2);
                continue;
            }
            int d1 = arr[i]/divisor;
            if (d1 % divisor != 0) continue;
            int d2 = d1/divisor;
            ans += (ull)cnt[arr[i]] * cnt[d1] * cnt[d2];
        }
    }
    for(int i=0; i<n; i++) {
        cnt[arr[i]] = 0;
        counted[arr[i]] = false;
    }
    cout<<ans<<"\n";
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/Lomba UGM/Find IT! UGM/Find IT! UGM 2023/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/Lomba UGM/Find IT! UGM/Find IT! UGM 2023/out", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}