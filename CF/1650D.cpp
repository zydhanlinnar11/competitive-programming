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
typedef vector<vi> vi2d;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vll2d;
typedef vector<string> vs;
typedef vector<vs> vs2d;
time_point<system_clock> chrono_time_start, chrono_time_end;
typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> pbds;
#define MOD 1000000007

inline ll modmul(ll a, ll b, ll mod = MOD) {
    return ((a % mod) * (b % mod)) % mod;
}

void swap (int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

inline void prog() {
    int n;
    cin>>n;
    vi arr(n), ans(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        arr[i]--;
    }
    for(int i=n-1; i>0; i--) {
        int loc = i;
        for(int j=i; j>=0; j--) {
            if(arr[j] == i) {
                loc = j;
                break;
            }
        }
        int rot = i - loc;
        rotate(arr.begin(), arr.begin() + loc + 1, arr.begin() + i + 1);
        ans[i] = (i - rot + 1) % (i + 1);
    }
    for(int i=0; i<n; i++) cout<<ans[i]<<" \n"[i == n - 1];
}

int main() {
    chrono_time_start = system_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef ZYD_WSL
        freopen("/home/zydhanlinnar11/cp/CF/in", "r", stdin);
        freopen("/home/zydhanlinnar11/cp/CF/out", "w", stdout);
    #endif
    int t = 1;
    cin>>t;
    while(t--) prog();
    chrono_time_end = system_clock::now();
    duration<double> elapsed = chrono_time_end - chrono_time_start;
    // cout<<"Time elapsed: "<<setprecision(3)<<fixed<<elapsed.count() * 1000<<" ms.\n";
    return 0;
}