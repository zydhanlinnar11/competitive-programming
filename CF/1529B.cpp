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
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vi> vi2d;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

inline void prog() {
    int n;
    cin>>n;
    vector<ll> arr(n);
    int cnt = 0, zero = 0;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        cnt += arr[i] <= 0;
        zero += arr[i] == 0;
    }
    ll mx = *max_element(arr.begin(), arr.end()), mn = *min_element(arr.begin(), arr.end());
    if(mx == 0) {
        cout<<n<<"\n";
        return;
    }
    if(mn > 0) {
        cout<<"1\n";
        return;
    }
    if(mn == 0) {
        cout<<min(2, n)<<"\n";
        return;
    }
    // cout<<cnt + min(1, n - cnt)<<"\n";
    // for(int i=0)
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++) {
        
    }
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/CP/CF/in", "r", stdin);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}