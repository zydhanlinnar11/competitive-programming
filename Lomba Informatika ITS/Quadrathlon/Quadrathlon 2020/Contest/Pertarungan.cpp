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
    char before2x = 'x', before = 'x';
    for(auto i : s) {
        if(before2x == before && before == i) {
            putchar((i == 'C' ? 'P' : 'T'));
            before2x = before = 'x';
            continue;
        } else putchar((i == 'C' ? 'B' : 'D'));
        before2x = before;
        before = i;
    }
    putchar('\n');
    return 0;
}