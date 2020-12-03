#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll mantap[10][1000], keren[10][1000];

void prec() {
    for(auto &i : mantap[9])
        i = 1;
    for(int i=0; i<10; i++)
        mantap[i][0] = 1;
    mantap[0][0] = 9;
    for(int i=1; i<1000; i++) {
        ll sum = 1;
        for(int j=8; j>=0; j--) {
            if(j == 0) {
                mantap[0][i] = sum;
                continue;
            }
            mantap[j][i] = (mantap[j + 1][i] + mantap[j][i - 1]) % MOD;
            sum = (sum + mantap[j][i]) % MOD;
        }
    }

    for(auto &i : keren[0])
        i = 1;
    for(int i=0; i<10; i++)
        keren[i][0] = 1;
    keren[9][0] = 9;
    for(int i=1; i<1000; i++) {
        ll sum = 1;
        for(int j=1; j<10; j++) {
            if(j == 9) {
                keren[9][i] = (sum + keren[9][i - 1]) % MOD;
                continue;
            }
            keren[j][i] = (keren[j - 1][i] + keren[j][i - 1]) % MOD;
            sum = (sum + keren[j][i]) % MOD;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    prec();
    int t;
    cin>>t;
    while(t--) {
        int a;
        cin>>a;
        cout<<mantap[0][a - 1]<<' '<<keren[9][a-1]<<'\n';
    }
}