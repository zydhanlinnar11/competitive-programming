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
    string s;
    cin>>s;
    int nr = 0, nb = 0, ng = 0;
    for(auto i : s)
        if(i == 'R')
            nr++;
        else if(i == 'G')
            ng++;
        else nb++;
    ull total = (ull)nr*ng*nb;
    for(int i=1; i<=n && total > 0; i++) {
        for(int j=0; (j + 2 * i) < n && total > 0; j++) {
            if(s[j] != s[j + i] && s[j + i] != s[j + 2 * i] && s[j] != s[j + 2 * i])
                if(total == 0ULL)
                    break;
                else total--;
        }
    }
    cout<<total<<'\n';
    return 0;
}