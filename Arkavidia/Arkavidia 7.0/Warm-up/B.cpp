#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
void func() {
    ull x, n;
    string cmd;
    cin>>x>>n>>cmd;
    if(cmd == "AND" || cmd == "OR" || (cmd == "XOR" && n % 2 == 1)) {
        for(int i=0; i<n; i++) {
            cout<<x;
            if(i == n - 1)
                cout<<'\n';
            else cout<<' ';
        }
    } else {
        for(int i=0; i<n-2; i++)
            cout<<1<<' ';
        if(x == 1)
            cout<<"2 3\n";
        else if(__builtin_popcount(x) == 1)
            cout<<(x | 1)<<' '<<1<<'\n';
        else {
            ull significant = pow(2, (ull)log2(x));
            cout<<(significant ^ x)<<' '<<significant<<'\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        func();
    return 0;
}