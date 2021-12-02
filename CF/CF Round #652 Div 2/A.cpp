#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned us;
typedef pair<int, int> pii;
#define unset unordered_set
#define unmap unordered_map
#define mpair make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        cout<<((((n * 90) % 360) == 0) ? "YES\n" : "NO\n");
    }
    return 0;
}