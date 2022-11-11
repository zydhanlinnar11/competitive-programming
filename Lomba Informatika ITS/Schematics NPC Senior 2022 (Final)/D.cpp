#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

int main() {
    string s;
    cin>>s;
    int n = s.length();
    vl prefsum(n+1, 0);
    for(int i=0; i + 3 < n; i++) {
        ll val = 0;
        for(int j=0; j<4; j++) {
            val = val * 10 + s[i + j] - '0';
        }
        prefsum[i + 4] = val % 8 == 0;
    }
    for(int i=1; i<=n; i++)
        prefsum[i] += prefsum[i - 1];
    // for(int i=0; i<=n; i++)
    //     cout<<prefsum[i]<<" \n"[i == n];
    for(int i=0; i < n; i++) {
        ll val = 0;
        ll cnt = 0;
        for(int j=0; j<3 && i + j < n; j++) {
            val = val * 10 + s[i + j] - '0';
            cnt += val % 8 == 0;
        }
        if(i + 3 <= n)
            cnt += prefsum.back() - prefsum[i + 3];
        cout<<cnt<<" \n"[i == n - 1];
    }
}