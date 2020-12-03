#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned us;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define unset unordered_set
#define unmap unordered_map
#define mpair make_pair

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        ll n, res = 0;
        cin>>n;
        while(1) {
            if(n % 6 == 0)
                n /= 6, res++;
            else if(n % 3 == 0)
                n *= 2, res++;
            else if(n == 1) {
                cout<<res<<'\n';
                break;
            } else {
                cout<<"-1\n";
                break;
            }
        }
    }
    return 0;
}