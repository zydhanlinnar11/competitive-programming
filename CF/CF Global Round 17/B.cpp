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

bool isPalindrome(vi &arr) {
    int n = (int)arr.size();
    for(int i=0; i<n/2; i++)
        if(arr[i] != arr[n - i - 1]) return false;
    return true;
}

inline void prog() {
    int n;
    cin>>n;
    vi arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    bool ans = isPalindrome(arr);
    vi arr2;
    for(int i=0; i<n; i++) {
        if(arr[i] == arr[0]) continue;
        arr2.push_back(arr[i]);
    }
    ans |= isPalindrome(arr2);
    arr2.clear();
    for(int i=0; i<n; i++) {
        if(arr[i] == arr[n - 1]) continue;
        arr2.push_back(arr[i]);
    }
    ans |= isPalindrome(arr2);
    for(int i=0; i<n/2; i++) {
        if(arr[i] == arr[n - i - 1]) continue;
        arr2.clear();
        for(int j=0; j<n; j++) {
            if(arr[j] == arr[i]) continue;
            arr2.push_back(arr[j]);
        }
        ans |= isPalindrome(arr2);
        arr2.clear();
        for(int j=0; j<n; j++) {
            if(arr[j] == arr[n - i - 1]) continue;
            arr2.push_back(arr[j]);
        }
        ans |= isPalindrome(arr2);
        break;
    }
    cout<<(ans ? "YES\n" : "NO\n");
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