#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n, k=2;
        cin>>n;
        // cout<<(((int)pow(2, k) - 1))<<'\n';
        while((n  % ((int)pow(2, k) - 1)) != 0) k++;
        cout<<(n  / ((int)pow(2, k) - 1))<<'\n';
    }
    return 0;
}